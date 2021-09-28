#include "functions.h"

int main() {
    int esercizio, min_ex = 1, max_ex = 3;
    int M;
    int *lista = NULL;

    srand(time(NULL));

    /** Menu **/
    do{
        printf("\nNumero dell'esercizio: ");
        scanf("%d", &esercizio);                // Immissione numero dell'esercizio
    }while(esercizio < min_ex || esercizio > max_ex);
    switch(esercizio){

        /** Esercizio 11_1: InsertionSort **/
        case 1:
            lista = genera_array(N);
            printf("\nLista non ordinata:");
            stampa_array(lista, N);
            insertionSort(lista, N);
            printf("\nLista ordinata:");
            stampa_array(lista, N);
            break;

        /** Esercizio 11_2: QuickSort **/
        case 2:
            lista = genera_array(N);
            printf("\nLista non ordinata:");
            stampa_array(lista, N);
            quickSort(lista, 0, N-1);
            printf("\nLista ordinata:");
            stampa_array(lista, N);
            break;

        /** Esercizio 11_3: Quick-Insertion Sort **/
        case 3:
            do{
                printf("\nValore M (minore di %d):\n", N-1);
                scanf("%d", &M);
            }while(M >= N-1);
            lista = genera_array(N);
            printf("\nLista non ordinata:");
            stampa_array(lista, N);
            quick_insertion_sort(lista, 0, N-1, M);
            printf("\nLista ordinata:");
            stampa_array(lista, N);
            break;
    }

    return 0;
}