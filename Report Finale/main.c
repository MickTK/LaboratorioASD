#include "functions.h"

int main(){
    _Bool debug_mod = true;                                // Modalità debug

    int *lista = NULL, *ordinata = NULL;
    int tipo_di_ordinamento, dimensione_vettore;
    int i;
    inputType ordine_riempimento_vettore;
    clock_t start, end;                                     // Calcolo del tempo
    double t;                                               // Calcolo del tempo

    /** Menu **/
    do{
        printf("\nDimensione vettore:\n");
        scanf("%d", &dimensione_vettore);
    }while(dimensione_vettore < 1);

    do{
        printf("\nOrdine di riempimento vettore: ");
        printf("\n[1] - Ordinato");
        printf("\n[2] - Quasi ordinato");
        printf("\n[3] - Inversamente ordinato");
        printf("\n[4] - Casuale");
        printf("\n");
        scanf("%d", &ordine_riempimento_vettore);
    }while(ordine_riempimento_vettore < 1 || ordine_riempimento_vettore > 4);

    do{
        printf("\nTipo di ordinamento: ");
        printf("\n[1] - Selection sort");
        printf("\n[2] - Insertion sort");
        printf("\n[3] - Quick sort");
        printf("\n[4] - Heap sort");
        printf("\n[5] - Merge sort");
        printf("\n");
        scanf("%d", &tipo_di_ordinamento);
    }while(tipo_di_ordinamento < 1 || tipo_di_ordinamento > 5);

    lista = genera_array(dimensione_vettore, ordine_riempimento_vettore);

    switch(tipo_di_ordinamento){

        /** Selection sort **/
        case 1:
            if(debug_mod){
                printf("\nLista non ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            start = clock();                                // (1/4) Calcolo del tempo
            selection_sort(lista, dimensione_vettore);
            end = clock();                                  // (2/4) Calcolo del tempo
            t = ((double) (end - start)) / CLOCKS_PER_SEC;  // (3/4) Calcolo del tempo
            if(debug_mod){
                printf("\n\nLista ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            printf("\n\nTempo impiegato: %lf secondi", t);    // (4/4) Calcolo del tempo
            break;

        /** Insertion sort **/
        case 2:
            if(debug_mod){
                printf("\nLista non ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            start = clock();                                // (1/4) Calcolo del tempo
            insertionSort(lista, dimensione_vettore);
            end = clock();                                  // (2/4) Calcolo del tempo
            t = ((double) (end - start)) / CLOCKS_PER_SEC;  // (3/4) Calcolo del tempo
            if(debug_mod){
                printf("\n\nLista ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            printf("\n\nTempo impiegato: %lf secondi", t);    // (4/4) Calcolo del tempo
            break;

        /** Quick sort **/
        case 3:
            if(debug_mod){
                printf("\nLista non ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            start = clock();                                // (1/4) Calcolo del tempo
            quickSort(lista, MIN-1, dimensione_vettore-1);
            end = clock();                                  // (2/4) Calcolo del tempo
            t = ((double) (end - start)) / CLOCKS_PER_SEC;  // (3/4) Calcolo del tempo
            if(debug_mod){
                printf("\n\nLista ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            printf("\n\nTempo impiegato: %lf secondi", t);    // (4/4) Calcolo del tempo
            break;

        /** Heap sort **/
        case 4:
            lista = genera_array(dimensione_vettore+1, ordine_riempimento_vettore);
            lista[0] = MIN;
            if(debug_mod){
                printf("\nLista non ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            start = clock();                                // (1/4) Calcolo del tempo
            heapsort(lista, dimensione_vettore-1);
            end = clock();                                  // (2/4) Calcolo del tempo
            t = ((double) (end - start)) / CLOCKS_PER_SEC;  // (3/4) Calcolo del tempo
            if(debug_mod){
                printf("\n\nLista ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            printf("\n\nTempo impiegato: %lf secondi", t);    // (4/4) Calcolo del tempo
            break;

        /** Merge sort (ricorsivo) **/
        case 5:
            ordinata = genera_array(dimensione_vettore+1, ordine_riempimento_vettore);
            if(debug_mod){
                printf("\nLista non ordinata:");
                stampa_array(lista, dimensione_vettore);
            }
            start = clock();                                // (1/4) Calcolo del tempo
            mergesort(lista, ordinata, MIN-1, dimensione_vettore-1);
            end = clock();                                  // (2/4) Calcolo del tempo
            t = ((double) (end - start)) / CLOCKS_PER_SEC;  // (3/4) Calcolo del tempo
            if(debug_mod){
                printf("\n\nLista ordinata:");
                stampa_array(ordinata, dimensione_vettore);
            }
            printf("\n\nTempo impiegato: %lf secondi", t);    // (4/4) Calcolo del tempo
            break;
    }
    return 0;
}