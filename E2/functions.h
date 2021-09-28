#ifndef E2_1_FUNCTIONS_H
#define E2_1_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 500
#define MIN 0
#define DIM_NOME 50

typedef enum {ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;

typedef struct{
    char nome[DIM_NOME];
    double prezzo_notte;
    int recensione;
} Hotel;

/** Esercizio 2_1: Selection Sort ricorsivo **/
int * genera_array(int dimensione, inputType tipo_schema);
int selectionSortRec(int A[], int dimA, int start);
void swap(int *A, int min, int i);

/** Esercizio 2_2 : Ordinamenti a confronto **/
void selection_sort(int A[], int n);
void print_confr_scambi(char x);

/** Esercizio 2_3 : ancora Ricerca Binaria **/
int findmin(int A[], int minpos, int start, int dim);
int ricercaBinariaIter(int *A, int numric, int dim);
int ricBinRic(int *A, int numric, int primo, int ultimo);
void selection_sort_hotel(Hotel B[], int n);
void stampa_lista_hotel(Hotel B[], int n);
int ricercaBinariaIter_hotel(Hotel *A, char nome[], int dim);

#endif //E2_1_FUNCTIONS_H