#include "functions.h"

/** Esercizio 12_1: Merge sort (ricorsivo) **/
void merge(int lista[], int ordinata[], int i, int m, int n){
    int j = m+1;             // indice per la seconda parte di lista
    int k = i;               // indice per la lista ordinata
    int pos_iniziale = i;    // posizione iniziale nella lista
    int t;

    while (i <= m && j <= n)
        if (lista[i] <= lista[j]){
            ordinata[k] = lista[i];
            i++;
            k++;
        }
        else{
            ordinata[k] = lista[j];
            j++;
            k++;
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

/** Esercizio 12_2: Heap sort **/
void adatta(int lista[], int radice, int n){
    int temp = lista[radice];
    int figlio = 2 * radice;     // figlio sx

    while (figlio <= n){

        /* Trova il maggiore tra il figlio sx e figlio dx */
        if (figlio < n && lista[figlio] < lista[figlio+1])
            figlio = figlio + 1;

        if (temp > lista[figlio])            // Confronta la radice e figlio max
            break;                           // Il padre di figlio sarà la posizione corretta
        else
            lista[figlio/2] = lista[figlio]; // Il figlio si sposta verso il padre
            figlio = 2 * figlio;             // Ripeti sul sottoalbero selezionato
    }
    lista[figlio/2] = temp;                  // Copia la radice nella posizione corretta
}
void heapsort(int lista[], int n){
    int i, x;

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