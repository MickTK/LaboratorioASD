#include "functions.h"

int main(){
    int *lista = genera_array(N);
    int ordinata[N];                                        // Menu
    int esercizio, min_ex = 1, max_ex = 2;                  // "
    clock_t start, end;                                     // Calcolo del tempo
    double t;                                               // Calcolo del tempo

    srand(time(NULL));

    /** Menu **/
    do{                                                     // Menu
        printf("\nNumero dell'esercizio: ");                // "
        scanf("%d", &esercizio);                            // "
    }while(esercizio < min_ex || esercizio > max_ex);       // "
    switch(esercizio){                                      // "

        /** Esercizio 12_1: Merge sort (ricorsivo) **/
        case 1:
            printf("\nLista non ordinata:");
            stampa_array(lista, N);
            start = clock();                                // (1/4) Calcolo del tempo
            mergesort(lista, ordinata, MIN-1, N-1);
            end = clock();                                  // (2/4) Calcolo del tempo
            t = ((double) (end - start)) / CLOCKS_PER_SEC;  // (3/4) Calcolo del tempo
            printf("\nLista ordinata:");
            stampa_array(ordinata, N);
            printf("\nTempo impiegato: %lf secondi", t);    // (4/4) Calcolo del tempo
            break;

        /** Esercizio 12_2: Heap sort **/
        case 2:
            lista = genera_array(N+1);
            lista[0] = MIN;
            printf("\nLista non ordinata:");
            stampa_array(lista, N);
            start = clock();                                // (1/4) Calcolo del tempo
            heapsort(lista, N-1);
            end = clock();                                  // (2/4) Calcolo del tempo
            t = ((double) (end - start)) / CLOCKS_PER_SEC;  // (3/4) Calcolo del tempo
            printf("\nLista ordinata:");
            stampa_array(lista, N);
            printf("\nTempo impiegato: %lf secondi", t);    // (4/4) Calcolo del tempo
            break;
    }
    return 0;
}