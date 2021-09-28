//
// Created by Michele Melis on 05/05/2020.
//

#ifndef E8_FUNCTIONS_H
#define E8_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_NOME 50
#define NUM_TEST 15

typedef struct
{
    char nome[DIM_NOME];
    float gradi;
    int bottiglie;
} Birra;

typedef struct nodo
{
    Birra key;
    struct nodo *parent;
    struct nodo *left;
    struct nodo *right;
} Nodo;

/* -------------------------------
 Funzioni gia' implementate:
 ------------------------------- */
Birra acquisisci_birra();
void stampa_birra(Birra b);

Nodo* crea_nodo(Birra b);
Nodo* carica_test();

/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node);
void inorder(Nodo* root);
void preorder(Nodo* root);
void postorder(Nodo* root);

int profondita(Nodo* root);
int max(int v1, int v2);

Nodo* ricerca(Nodo* root, char* nome_birra);

Nodo* abr_min(Nodo* root);
Nodo* abr_max(Nodo* root);

Nodo* abr_succ(Nodo* x);
Nodo* abr_pred(Nodo* x);

Nodo* delete_node(Nodo* root, Nodo* nodo);

#endif //E8_FUNCTIONS_H