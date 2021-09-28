#ifndef E11_FUNCTIONS_H
#define E11_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define N 100

void scambia(int lista[], int x, int y);
int perno(int lista[], int primo, int ultimo);
void quickSort(int lista[], int u, int v);
int * genera_array(int dimensione);
void stampa_array(int lista[], int dim);
void insertionSort(int lista[], int dim);
void quick_insertion_sort(int lista[], int u, int v, int M);

#endif //E11_FUNCTIONS_H