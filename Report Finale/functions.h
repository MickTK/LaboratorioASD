#ifndef REPORT_FINALE_FUNCTIONS_H
#define REPORT_FINALE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN 1
#define N 100

typedef enum {ORDINATO = 1, QUASI_ORDINATO = 2, INV_ORDINATO = 3, CASUALE = 4} inputType;

/** Selection sort **/
void swap(int *A, int i, int j);
void selection_sort(int *A, int n);

/** Insertion sort **/
void insertionSort(int lista[], int dim);

/** Quick sort **/
int perno(int lista[], int primo, int ultimo);
void quickSort(int lista[], int u, int v);

/** Heap sort **/
void adatta(int lista[], int radice, int n);
void heapsort(int lista[], int n);

/** Merge sort (ricorsivo) **/
void merge(int lista[], int ordinata[], int i, int m, int n);
void mergesort(int lista[], int ordinata[], int lower, int upper);

int * genera_array(int dimensione, inputType tipo_schema);
void stampa_array(int lista[], int dim);

void stmp();
void glb_vrs_reset();

#endif //REPORT_FINALE_FUNCTIONS_H