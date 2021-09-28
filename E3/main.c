#include "functions.h"

int main(){
    /** Variabili e vettori **/
    int matrix[NUMR][NUMC] = {{0}};
    int numric = 71;                                              // valore da cercare nella matrice
    Tripla *matrice_triple = NULL, *trasp_matrice_triple = NULL;
    int esercizio = 0;

    /** Menu **/
    do{
        printf("\nNumero dell'esercizio: ");
        scanf("%d", &esercizio);                                  // Immissione numero dell'esercizio
    }while(esercizio < 1 || esercizio > 4);
    switch(esercizio){
        case 1:

            /** Esercizio 3_1: Creazione Matrice Sparsa **/
            matrice_triple = input_matrice(NUMR, NUMC);           // Inserimento valori della matrice
            riempimento_matrice_sparsa(matrix, matrice_triple);   // Copia valori nella matrice sparsa

            break;
        case 2:

            /** Esercizio 3_2: Stampa Matrice Sparsa **/
            matrice_triple = input_matrice(NUMR, NUMC);           // Inserimento valori della matrice
            riempimento_matrice_sparsa(matrix, matrice_triple);   // Copia valori nella matrice sparsa
            print_classic_matrix(matrix, NUMR, NUMC);             // Stampa matrice sparsa

            break;
        case 3:

            /** Esercizio 3_3: Ricerca di un valore **/
            matrice_triple = input_matrice(NUMR, NUMC);           // Inserimento valori della matrice
            riempimento_matrice_sparsa(matrix, matrice_triple);   // Copia valori nella matrice sparsa
            printf("\nValore da cercare nella matrice: ");
            scanf("%d", &numric);                                 // Immissione valore da ricercare nella matrice
            search_element_in_classic_matrix(matrix, NUMR, NUMC, numric);   // Ricerca valore
            print_classic_matrix(matrix, NUMR, NUMC);             // Stampa matrice sparsa

            break;
        case 4:

            /** Esercizio 3_4: Matrici Trasposte **/
            matrice_triple = input_matrice(NUMR, NUMC);           // Inserimento valori della matrice
            trasp_matrice_triple = (Tripla *) malloc(sizeof(Tripla) * (matrice_triple[0].valore + 1)); // Alloccazione dinamica di memoria per la matrice trasposta
            trasp_rapida(matrice_triple, trasp_matrice_triple);   // Trasposizione
            riempimento_matrice_sparsa(matrix, trasp_matrice_triple);   // Copia valori nella matrice sparsa
            print_classic_matrix(matrix, NUMR, NUMC);             // Stampa matrice sparsa

            break;
    }

    return 0;
}