#include "functions.h"

static int cont_confr_iter = 0, cont_scambi_iter = 0, cont_confr_ric = 0, cont_scambi_ric = 0;

int * genera_array(int dimensione, inputType tipo_schema){
    int i, j;
    int *A = NULL;

    srand(time(NULL));                                            // Seed generazione casuale

    A = (int *) malloc(dimensione * sizeof(int));
    /* Elementi ordinati */
    if(tipo_schema == ORDINATO){
        for(i = 0; i < N; i++){
            A[i] = i + 1 ;
        }
    }

    /* Elementi inversamente ordinati */
    if(tipo_schema == INV_ORDINATO){
        for(i = N-1, j = 1; i >= 0; i--, j++){
            A[i] = j;
        }
    }

    /* Elementi parzialmente ordinati */
    if(tipo_schema == QUASI_ORDINATO){
        for(i = 0; i < dimensione; i++){
            if(i < dimensione/2){           // Elementi ordinati fino a metà dimensione del vettore
                A[i] = i + 1 ;
            }
            /* Metà ordine casuale */
            if(i > dimensione/2){           // Elementi casuali da metà vettore
                A[i] = (dimensione/2) + rand()%(dimensione - (dimensione/2) + 1);
                /*
                 * Genera un numero casuale tra MIN e dimensione/2 dopodichè gli aggiunge i
                 * valori che sono già stati generati in ordine
                 * */
            }
        }
    }

    /* Elementi random */
    if(tipo_schema == CASUALE){
        /* Riempimento vettore */
        for(i = 0; i < dimensione; i++){
            A[i] = MIN + rand()%(dimensione - MIN + 1);
        }
    }

    return A;
}
int selectionSortRec(int A[], int dimA, int start){
    int minIndex = 0;

    if(start >= dimA - 1)
        return -1;

    minIndex = findmin(A, start, start + 1, dimA);
    cont_confr_ric++;
    swap(A, minIndex, start);
    cont_scambi_ric++;
    selectionSortRec(A, dimA, start + 1);
}
int findmin(int A[], int minpos, int start, int dim){
    if (start == dim)
        return minpos;
    if (A[start] < A[minpos])
        minpos = start;
    return findmin(A, minpos, start + 1, dim);
}
void swap(int *A, int min, int i){
    int x = 0;

    /* Scambia A[min] con A[i] */
    x = A[min];
    A[min] = A[i];
    A[i] = x;
}
void selection_sort(int A[], int n){
    int i, j;

    /* N1 */
    for(i = 0; i < n-1; i++){
        /* N2 */
        for(j = i+1; j < n; j++){
            cont_confr_iter++;        // Update confronti
            /* In caso di scambio */
            if(A[i] > A[j]){
                cont_scambi_iter++;   // Update scambi
                swap(A, i, j);        // Scambio
            }
        }
    }
}
void print_confr_scambi(char x){
    if(x == 'r'){
        printf("\nSelection sort ricorsivo");
        printf("\nConfronti: %d", cont_confr_ric);
        printf("\n   Scambi: %d", cont_scambi_ric);
    }
    if(x == 'i'){
        printf("\nSelection sort iterativo");
        printf("\nConfronti: %d", cont_confr_iter);
        printf("\n   Scambi: %d", cont_scambi_iter);
    }
}
int ricercaBinariaIter(int *A, int numric, int dim){
    int contBI = 0;        // Variabile per il conto delle celle analizzate
    int primo = 0;         // Variabile con la prima cella della selezione
    int ultimo = dim - 1;  // Variabile con l'ultima cella della selezione
    int mezzo = 0;         // Variabile con l'indice della cella centrale del vettore

    while (primo <= ultimo){
        mezzo = (primo + ultimo) / 2; // Calcolo della cella centrale del vettore
        if (numric < A[mezzo]) {      // In caso il numero ricercato si trovi nella prima metà della sezione
            ultimo = mezzo - 1;       // Si riduce il range della ricerca
            contBI++;                 // Conteggio controllo
        }
        else if (numric == A[mezzo]){ // In caso di numero corrispondente al numero ricercato
            printf("\nCelle analizzate: %d", contBI);   // Stampa a video
            return mezzo;             // Valore dell'indice con il numero ricercato
        }
        else{                         // In caso il numero ricercato si trovi nella seconda metà della sezione
            primo = mezzo + 1;        // Si riduce il range della ricerca
            contBI++;                 // Conteggio controllo
        }
    }
    return -1;                        // In caso di numero non presente nel vettore
}
int ricBinRic(int *A, int numric, int primo, int ultimo){
    static int contBR = 0;
    int mezzo = 0;

    if (primo > ultimo)
        return -1;

    mezzo = (primo + ultimo)/2;

    if (A[mezzo] == numric) {
        printf("\nCelle analizzate: %d", contBR);
        return mezzo;
    }
    else if (A[mezzo] < numric) {
        contBR++;
        return ricBinRic(A, numric, mezzo + 1, ultimo);
    }
    else {
        contBR++;
        return ricBinRic(A, numric, primo, mezzo - 1);
    }
}
void selection_sort_hotel(Hotel B[], int n){
    int i, j;
    Hotel app;

    /* N1 */
    for(i = 0; i < n-1; i++){
        /* N2 */
        for(j = i+1; j < n; j++){
            /* In caso di scambio */
            if(B[i].nome[0] > B[j].nome[0]){
                strcpy(app.nome, B[i].nome);
                app.recensione = B[i].recensione;
                app.prezzo_notte = B[i].prezzo_notte;

                strcpy(B[i].nome, B[j].nome);
                B[i].recensione = B[j].recensione;
                B[i].prezzo_notte = B[j].prezzo_notte;

                strcpy(B[j].nome, app.nome);
                B[j].recensione = app.recensione;
                B[j].prezzo_notte = app.prezzo_notte;
            }
        }
    }
}
void stampa_lista_hotel(Hotel B[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("\nHotel %d di %d", i+1, n);
        printf("\nNome: %s", B[i].nome);
        printf("\nRecensione: %d", B[i].recensione);
        printf("\nPrezzo per notte: %g", B[i].prezzo_notte);
        printf("\n");
    }
}
int ricercaBinariaIter_hotel(Hotel *A, char nome[], int dim){
    int primo = 0;         // Variabile con la prima cella della selezione
    int ultimo = dim - 1;  // Variabile con l'ultima cella della selezione
    int mezzo = 0;         // Variabile con l'indice della cella centrale del vettore

    while (primo <= ultimo){
        mezzo = (primo + ultimo) / 2; // Calcolo della cella centrale del vettore
        if (strcasecmp(nome, A[mezzo].nome) < 0) {      // In caso il numero ricercato si trovi nella prima metà della sezione
            ultimo = mezzo - 1;       // Si riduce il range della ricerca
        }
        else if (strcasecmp(nome, A[mezzo].nome) == 0){ // In caso di numero corrispondente al numero ricercato
            return mezzo;             // Valore dell'indice con il numero ricercato
        }
        else{                         // In caso il numero ricercato si trovi nella seconda metà della sezione
            primo = mezzo + 1;        // Si riduce il range della ricerca
        }
    }
    return -1;                        // In caso di numero non presente nel vettore
}