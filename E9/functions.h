#ifndef E9_FUNCTIONS_H
#define E9_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICI 20
#define DIM 50
#define NUM_NODI_TEST 11

typedef struct node{
    int vertex_id;
    struct node* link;
}Node;

typedef struct{
    char nome[DIM];
    int  abitanti;
    char nazione[DIM];
    Node* lista_adj;
}Citta;

typedef struct{
    Node* front;
    Node* back;
    int cont;
}Queue;

/* ==============================
 * Funzioni gia' implementate
 * ============================== */
void carica_citta_test(Citta grafo[]);
void carica_grafo_test_orientato(Citta grafo[], int num_nodi);
void carica_grafo_test_non_orientato(Citta grafo[], int num_nodi);


/* ==============================
 * Funzioni da completare
 * ============================== */
void aggiungi_nodo(Citta grafo[], int *num_nodi);
void crea_arco(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void stampa_lista_adiacenze(Citta grafo[], int num_nodi);

void DFS(Citta grafo[], int visited[], int start_id);
void BFS(Citta grafo[], int visited[], int start_id);

void cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);

void componenti_connesse(Citta grafo[], int visited[], int num_nodi);


//prototipi funzioni per la gestione della Coda
_Bool isEmptyQueue(Queue *p);
_Bool isFullQueue(Queue *p);
void pushQueue(Queue *p, int val);
int popQueue(Queue *p);

/** Menu **/
void case_2(Citta grafo[], int num_nodi);
void case_4(Citta grafo[], int visited[]);
void case_5(Citta grafo[], int visited[]);
void case_6(Citta grafo[], int visited[], int num_nodi);
void case_7(Citta grafo[], int visited[], int num_nodi);

#endif //E9_FUNCTIONS_H
