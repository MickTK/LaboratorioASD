#ifndef E12_FUNCTIONS_H
#define E12_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define N 10000

/** Esercizio 12_1: Merge sort (ricorsivo) **/
void merge(int lista[], int ordinata[], int i, int m, int n);
void mergesort(int lista[], int ordinata[], int lower, int upper);

/** Esercizio 12_2: Heap sort **/
void adatta(int lista[], int radice, int n);
void heapsort(int lista[], int n);

int * genera_array(int dimensione);
void stampa_array(int lista[], int dim);

#endif //E12_FUNCTIONS_H