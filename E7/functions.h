//
// Created by Michele Melis on 30/04/2020.
//

#ifndef E7_FUNCTIONS_H
#define E7_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define DIM_NOME 50
#define DIM_HEAP 50

//stuttura che rappresenta un Pronto soccorso
typedef struct
{
    int numeroB;
    int numeroG;
    int numeroV;
    int numeroR;
} ProntoSoccorso;

//enumerazione che rappresenta i codici del pronto soccorso
typedef enum {BIANCO, VERDE, GIALLO, ROSSO} Codice;

//struttura che rappresenta un Paziente
typedef struct
{
    char nome[DIM_NOME];
    Codice codice;
    int ordine;
}Paziente;

/*funzione che chiede i dati relativi ad un nuovo paziente e lo restituisce (con il campo ordine calcolato automaticamente),
pronto per essere inserito nella coda con priorita' (heap) */
Paziente nuovoPaziente(ProntoSoccorso *ps);

int priorita(Paziente p1, Paziente p2);
void insertHeap(Paziente heap[], Paziente item, int *n);
Paziente deleteHeap(Paziente heap[], int *n);
void printHeap(Paziente heap[], int dim_coda);
#endif //E7_FUNCTIONS_H
