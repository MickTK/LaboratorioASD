#include "functions.h"

void scambia(int lista[], int x, int y){
    int a = lista[x];
    lista[x] = lista[y];
    lista[y] = a;
}
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
        if(i < j)
            scambia(lista, i, j);
    }

    scambia(lista, primo, j);
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
int * genera_array(int dimensione){
    int i, j;
    int *A = NULL;

    A = (int *) malloc(dimensione * sizeof(int));

    /* Riempimento vettore */
    for(i = 0; i < dimensione; i++){
        A[i] = MIN + rand()%(dimensione - MIN + 1);
    }

    return A;
}
void stampa_array(int lista[], int dim){
    int i = 0;

    printf("\n");
    for(i = 0; i < dim; i++){
        printf("%d ", lista[i]);
    }
}
void insertionSort(int lista[], int dim){
    int i, j, prossimo;

    for(i = 1; i <= dim-1; i++){
        prossimo = lista[i];
        for (j = i-1; j >= 0; j--){
            if (prossimo < lista[j])
                lista[j+1] = lista[j];
            else
                break;
        }
        lista[j+1] = prossimo;
    }
}
void quick_insertion_sort(int lista[], int u, int v, int M){
    int q = 0;
    int dim_sottolista_sin, dim_sottolista_des;

    if (u == v) return;

    q = perno(lista, u, v);
    dim_sottolista_sin = u + (q-1);
    dim_sottolista_des = v - (q+1);

    if (u < q && dim_sottolista_sin > M)
        quickSort(lista, u, q-1);
    else if(dim_sottolista_sin <= M)
        insertionSort(lista, v);

    if (q < v && dim_sottolista_des > M)
        quickSort(lista, q+1, v);
    else if(dim_sottolista_des <= M)
        insertionSort(lista, v);
}