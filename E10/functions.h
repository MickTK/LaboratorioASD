#ifndef E10_FUNCTIONS_H
#define E10_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TARGA 10
#define NUM_PIANI 7

typedef struct
{
    char targa[MAX_TARGA];
    int ora;
    int min;
}Auto;

typedef struct nodo
{
    Auto info;
    struct nodo *link;
}Nodo;

int hash_function(char targa[]);
Auto acquisisci_auto();
void inserisci_auto(Nodo* parcheggio[], Auto a);
void carica_auto_test(Nodo* parcheggio[]);
void stampa_parcheggio(Nodo* parcheggio[]);
void stampa_piano(Nodo* parcheggio[], int piano);
Nodo* ricerca_auto(Nodo* parcheggio[], char targa[]);
void elimina_auto(Nodo* parcheggio[], char targa[]);

#endif //E10_FUNCTIONS_H