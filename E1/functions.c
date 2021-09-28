//
// Created by Michele Melis on 05/03/2020.
//

#include "functions.h"

/** Esercizio 1_1: Selection Sort iterativo **/
int * genera_array(int dimensione, inputType tipo_schema){
    int i, j;
    int *A = NULL;

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
            else{           // Elementi casuali da metà vettore
                A[i] = (MIN + rand()%((dimensione/2) - MIN + 1)) + (dimensione/2);
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
void swap(int *A, int i, int j){
    int x = 0;

    /* Scambia A[min] con A[i] */
    x = A[j];
    A[j] = A[i];
    A[i] = x;
}
void selection_sort(int *A, int n){
    int i, j;

    /* N1 */
    for(i = 0; i < n-1; i++){
        /* N2 */
        for(j = i+1; j < n; j++){
            /* In caso di N1 > N2 */
            if(A[i] > A[j]){
                swap(A, i, j);   // Scambia i due numeri
            }
        }
    }
}

/** Esercizio 1_2: difficoltà++ **/
Ricetta * allocca_memoria(Ricetta *ricetta, int n){
    if(ricetta == NULL)
        ricetta = (Ricetta *) malloc(n * sizeof(Ricetta));
    else
        ricetta = (Ricetta *) realloc(ricetta, n * sizeof(Ricetta));

    return ricetta;
}
void nuova_ricetta(Ricetta *ricetta, int n){
    getchar();
    printf("\nNome:\n");
    scanf("%[^\n]s", ricetta[n-1].nome);
    printf("\nTempo:\n");
    scanf("%lg", &ricetta[n-1].tempo);
    do{
        printf("\nDifficolta\' (tra 1 e 10):\n");
        scanf("%d", &ricetta[n - 1].difficolta);
    }while(ricetta[n - 1].difficolta < MIN_DIF || ricetta[n - 1].difficolta > MAX_DIF);
}
void stampa_ricette(Ricetta *ricetta, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("\n#%d", i+1);
        printf("\nNome:        %s", ricetta[i].nome);
        printf("\nTempo:       %lf", ricetta[i].tempo);
        printf("\nDifficolta\': %d", ricetta[i].difficolta);
    }
    printf("\n");
}
_Bool compare(Ricetta r1, Ricetta r2){
    if(r1.tempo < r2.tempo)
        return false;
    else if(r1.tempo == r2.tempo && r1.difficolta < r2.difficolta)
        return false;
    else
        return true;
}
void selection_sort_ricetta(Ricetta *ricetta, int n){
    int i, j;

    /* Ricetta 1 */
    for(i = 0; i < n-1; i++){
        /* Ricetta 2 */
        for(j = i+1; j < n; j++){
            /* In caso di scambio */
            if(compare(ricetta[i], ricetta[j]) == true){
                swap_ricetta(ricetta[i], ricetta[j]);   // Scambia le due ricette
            }
        }
    }
}
void swap_ricetta(Ricetta r1, Ricetta r2){
    Ricetta x;

    /* Scambio */
    strcpy(x.nome, r2.nome);
    strcpy(r2.nome, r1.nome);
    strcpy(r1.nome, x.nome);
    x.tempo = r2.tempo;
    r2.tempo = r1.tempo;
    r1.tempo = x.tempo;
    x.difficolta = r2.difficolta;
    r2.difficolta = r1.difficolta;
    r1.difficolta = x.difficolta;


}

/** Esercizio 1_3: Ricerca lineare **/
int ricercaBanale(int *A, int numric, int dim){
    int pos = 0;
    int contL = 0;  // Counter

    while (pos < dim && A[pos] <= numric){
        if (numric == A[pos]){
            contL = pos + 1;
            printf("\nCelle analizzate: %d", contL);
            return pos;
        }
        else{
            pos++;
            contL++;
        }
    }
    return -1;
}

/** Esercizio 1_4: Ricerca binaria iterativa **/
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

/** Esercizio 1_5: Ricerca binaria ricorsiva **/
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