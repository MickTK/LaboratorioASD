#include "functions.h"

_Bool debug_mod = false;                                      // Modalità debug
int counter_cmp = 0, counter_swap = 0;

/** Selection sort **/
void swap(int *A, int i, int j){
    int x = 0;

    /* Scambia A[min] con A[i] */
    x = A[j];
    A[j] = A[i];
    A[i] = x;
}
void selection_sort(int *A, int n){
    int i, j;

    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(debug_mod)           // Debug
                counter_cmp++;
            if(A[i] > A[j]){
                swap(A, i, j);
                if(debug_mod)           // Debug
                    counter_swap++;
            }
        }
    }

    if(debug_mod){           // Debug
        printf("\nConfronti: %d", counter_cmp);
        printf("\nScambi: %d", counter_swap);
    }

}

/** Insertion sort **/
void insertionSort(int lista[], int dim){
    int i, j, prossimo;

    for(i = 1; i <= dim-1; i++){
        prossimo = lista[i];
        for (j = i-1; j >= 0; j--){
            if(debug_mod){           // Debug
                counter_cmp++;
            }
            if(prossimo < lista[j]){
                lista[j + 1] = lista[j];
                if(debug_mod){           // Debug
                    counter_swap++;
                }
            }
            else
                break;
        }
        lista[j+1] = prossimo;
    }

    if(debug_mod){           // Debug
        printf("\nConfronti: %d", counter_cmp);
        printf("\nScambi: %d", counter_swap);
    }
}

/** Quick sort **/
int perno(int lista[], int primo, int ultimo){
    int i = primo;
    int j = ultimo + 1;
    int pivot = lista[primo];

    while (i < j){
        do{
            i = i+1;

        }while(lista[i] <= pivot && i <= ultimo);
        do{
            j = j-1;

        }while(lista[j] > pivot && j >= primo);

        if(i < j){
            swap(lista, i, j);
            if(debug_mod) counter_swap++;     // Debug
        }

        if(debug_mod) counter_cmp++;          // Debug
    }

    swap(lista, primo, j);

    return j;
}
void quickSort(int lista[], int u, int v){
    int q = 0;

    if (u == v) return;

    q = perno(lista, u, v);

    if (u < q)
        quickSort(lista, u, q-1);
    if (q < v)
        quickSort(lista, q+1, v);
}

/** Heap sort **/
void adatta(int lista[], int radice, int n){
    int temp = lista[radice];
    int figlio = 2 * radice;                 // figlio sx

    while (figlio <= n){

        if(debug_mod) counter_cmp++;         // Debug

        /* Trova il maggiore tra il figlio sx e figlio dx */
        if (figlio < n && lista[figlio] < lista[figlio+1])
            figlio = figlio + 1;

        if (temp > lista[figlio])            // Confronta la radice e figlio max
            break;                           // Il padre di figlio sarà la posizione corretta
        else{
            lista[figlio / 2] = lista[figlio]; // Il figlio si sposta verso il padre

            if(debug_mod) counter_swap++;    // Debug
        }
        figlio = 2 * figlio;                 // Ripeti sul sottoalbero selezionato
    }
    lista[figlio/2] = temp;                  // Copia la radice nella posizione corretta
}
void heapsort(int lista[], int n){
    int i, x;

    if(debug_mod){           // Debug
        counter_cmp = 0;
        counter_swap = 0;
    }

    /* Si costruisce lo heap associato all'insieme da ordinare lista */
    for (i = n/2; i >= 1; i--)
        adatta(lista, i, n);

    for (i = n-1; i >= 1; i--){

        /* Si estrae, di volta in volta, il massimo lista[1] e lo si posiziona in fondo alla sequenza */
        x = lista[1];
        lista[1] = lista[i+1];
        lista[i+1] = x;

        /* Si opera nuovamente sullo heap ridotto di un elemento */
        adatta(lista, 1, i);
    }

    if(debug_mod){           // Debug
        printf("\nConfronti: %d", counter_cmp);
        printf("\nScambi: %d", counter_swap);
    }
}

/** Merge sort (ricorsivo) **/
void merge(int lista[], int ordinata[], int i, int m, int n){
    int j = m+1;             // indice per la seconda parte di lista
    int k = i;               // indice per la lista ordinata
    int pos_iniziale = i;    // posizione iniziale nella lista
    int t;

    while(i <= m && j <= n){
        if (debug_mod) counter_cmp++;   // Debug

        if (lista[i] <= lista[j]){
            if (debug_mod) counter_swap++;   // Debug
            ordinata[k] = lista[i];
            i++;
            k++;
        }
        else{
            if (debug_mod) counter_swap++;   // Debug
            ordinata[k] = lista[j];
            j++;
            k++;
        }
    }

    if (i > m)                              // ordinata[k],..., ordinata[n] ← lista[j],..., lista[n]
        for (t = j; t <= n; t++)
            ordinata[k + t - j] = lista[t];
    else                                    // ordinata[k],..., ordinata[n] ← lista[i],..., lista[m]
        for (t = i; t <= m; t++)
            ordinata[k + t - i] = lista[t];

    for (i = pos_iniziale; i <= n; i++)
        lista[i] = ordinata[i];
}
void mergesort(int lista[], int ordinata[], int lower, int upper){
    int medium = 0;

    if (lower >= upper) return;
    medium = (lower + upper)/2;
    mergesort(lista, ordinata, lower, medium);
    mergesort(lista, ordinata, medium+1, upper);
    merge(lista, ordinata, lower, medium, upper);
}

int * genera_array(int dimensione, inputType tipo_schema){
    int i, j;
    int *A = NULL;

    A = (int *) malloc(dimensione * sizeof(int));

    srand(time(NULL));

    /* Elementi ordinati */
    if(tipo_schema == ORDINATO){
        for(i = 0; i < dimensione; i++){
            A[i] = i + 1 ;
        }
    }

    /* Elementi inversamente ordinati */
    if(tipo_schema == INV_ORDINATO){
        for(i = dimensione-1, j = 1; i >= 0; i--, j++){
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
void stampa_array(int lista[], int dim){
    int i, j;
    int num_per_riga = 20;

    printf("\n");
    for(i = 0, j = 0; i < dim; i++, j++){
        if(j == num_per_riga-1){
            printf("\n");
            j = 0;
        }
        printf("%d ", lista[i]);
    }
}

void stmp(){
    if(debug_mod){           // Debug
        printf("\nConfronti: %d", counter_cmp);
        printf("\nScambi: %d", counter_swap);
    }
}
void glb_vrs_reset(){
    counter_swap = 0;
    counter_cmp = 0;
}