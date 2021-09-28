//
// Created by Michele Melis on 05/03/2020.
//

#ifndef E1_3_FUNCTIONS_H
#define E1_3_FUNCTIONS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 100                                                     // Esercizio 1_1: Selection Sort iterativo
#define MIN 1                                                     // Esercizio 1_1: Selection Sort iterativo
#define MAX_DIF 10                                                // Esercizio 1_2: difficoltà++
#define MIN_DIF 1                                                 // Esercizio 1_2: difficoltà++
#define DIM_NOME 101                                              // Esercizio 1_2: difficoltà++

typedef struct{
    char nome[DIM_NOME];
    double tempo;
    int difficolta;
} Ricetta;                                                        // Esercizio 1_2: difficoltà++

typedef enum {
    ORDINATO,
    QUASI_ORDINATO,
    INV_ORDINATO,
    CASUALE
} inputType;                                                      // Esercizio 1_1: Selection Sort iterativo

/** Esercizio 1_1: Selection Sort iterativo **/
int * genera_array(int dimensione, inputType tipo_schema);
void swap(int *A, int i, int j);
void selection_sort(int *A, int n);

/** Esercizio 1_2: difficoltà++ **/
Ricetta * allocca_memoria(Ricetta *ricetta, int n);
void nuova_ricetta(Ricetta *ricetta, int n);
void stampa_ricette(Ricetta *ricetta, int n);
_Bool compare(Ricetta r1, Ricetta r2);
void selection_sort_ricetta(Ricetta *ricetta, int n);
void swap_ricetta(Ricetta r1, Ricetta r2);

/** Esercizio 1_3: Ricerca lineare **/
int ricercaBanale(int *A, int numric, int dim);

/** Esercizio 1_4: Ricerca binaria iterativa **/
int ricercaBinariaIter(int *A, int numric, int dim);

/** Esercizio 1_5: Ricerca binaria ricorsiva **/
int ricBinRic(int *A, int numric, int primo, int ultimo);

#endif //E1_3_FUNCTIONS_H