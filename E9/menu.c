#include "functions.h"


void case_2(Citta grafo[], int num_nodi){
    int n1, n2;

    printf("\nid coda:\n");
    scanf("%d", &n1);
    printf("\nid testa:\n");
    scanf("%d", &n2);

    crea_arco(grafo, n1, n2, num_nodi);
}
void case_4(Citta grafo[], int visited[]){
    int n1 = 0, i = 0;

    printf("\nid start:\n");
    scanf("%d", &n1);

    printf("\n");
    DFS(grafo, visited, n1);
}
void case_5(Citta grafo[], int visited[]){
    int n1 = 0;

    printf("\nid start:\n");
    scanf("%d", &n1);

    BFS(grafo, visited, n1);
}
void case_6(Citta grafo[], int visited[], int num_nodi){
    int n1, n2, i;

    printf("\nid coda:\n");
    scanf("%d", &n1);
    printf("\nid testa:\n");
    scanf("%d", &n2);

    cancella_arco_orientato(grafo, n1, n2, num_nodi);
}
void case_7(Citta grafo[], int visited[], int num_nodi){
    int n1, n2, i;

    printf("\nid coda:\n");
    scanf("%d", &n1);
    printf("\nid testa:\n");
    scanf("%d", &n2);

    cancella_arco_non_orientato(grafo, n1, n2, num_nodi);
}