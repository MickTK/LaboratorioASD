//
// Created by Michele Melis on 31/03/2020.
//

#ifndef E3_1_FUNCTIONS_H
#define E3_1_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define NUMC 15
#define NUMR 10

typedef struct {
    int riga;
    int colonna;
    int valore;
} Tripla;

int numUsedIntegerClassic;  //variabile da usare per contare il numero di interi nella matrice tradizionale
int numUsedIntegerSparse;   //variabile da usare per contare il numero di interi nella matrice sparsa

Tripla * input_matrice(int numr, int numc);
void riempimento_matrice_sparsa(int matrix[][NUMC], Tripla matrice_tripla[]);

void fill_classic_matrix(int matrix[][NUMC], int numr, int numc);
void print_classic_matrix(int matrix[][NUMC], int numr, int numc);
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric);
void trasp_rapida(Tripla *a, Tripla *b);

#endif //E3_1_FUNCTIONS_H