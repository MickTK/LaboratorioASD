#include "functions.h"

void carica_citta_test(Citta grafo[]){
    //Cagliari
    strcpy(grafo[0].nome, "Cagliari");
    strcpy(grafo[0].nazione, "Italia");
    grafo[0].abitanti = 300000;
    grafo[0].lista_adj = NULL;

    //Zurigo
    strcpy(grafo[1].nome, "Zurigo");
    strcpy(grafo[1].nazione, "Svizzera");
    grafo[1].abitanti = 400000;
    grafo[1].lista_adj = NULL;

    //Lione
    strcpy(grafo[2].nome, "Lione");
    strcpy(grafo[2].nazione, "Francia");
    grafo[2].abitanti = 500000;
    grafo[2].lista_adj = NULL;

    //Genova
    strcpy(grafo[3].nome, "Genova");
    strcpy(grafo[3].nazione, "Italia");
    grafo[3].abitanti = 800000;
    grafo[3].lista_adj = NULL;

    //Roma
    strcpy(grafo[4].nome, "Roma");
    strcpy(grafo[4].nazione, "Italia");
    grafo[4].abitanti = 4000000;
    grafo[4].lista_adj = NULL;

    //New York
    strcpy(grafo[5].nome, "New York");
    strcpy(grafo[5].nazione, "USA");
    grafo[5].abitanti = 8500000;
    grafo[5].lista_adj = NULL;

    //Bilbao
    strcpy(grafo[6].nome, "Bilbao");
    strcpy(grafo[6].nazione, "Spagna");
    grafo[6].abitanti = 350000;
    grafo[6].lista_adj = NULL;

    //Berlino
    strcpy(grafo[7].nome, "Berlino");
    strcpy(grafo[7].nazione, "Germania");
    grafo[7].abitanti = 3500000;
    grafo[7].lista_adj = NULL;

    //Londra
    strcpy(grafo[8].nome, "Londra");
    strcpy(grafo[8].nazione, "Gran Bretagna");
    grafo[8].abitanti = 8700000;
    grafo[8].lista_adj = NULL;

    //Miami
    strcpy(grafo[9].nome, "Miami");
    strcpy(grafo[9].nazione, "USA");
    grafo[9].abitanti = 450000;
    grafo[9].lista_adj = NULL;

    //Tokyo
    strcpy(grafo[10].nome, "Tokyo");
    strcpy(grafo[10].nazione, "Giappone");
    grafo[10].abitanti = 13700000;
    grafo[10].lista_adj = NULL;
}
void carica_grafo_test_orientato(Citta grafo[], int num_nodi){

    carica_citta_test(grafo);

    //Creazione archi
    crea_arco(grafo, 0, 1, num_nodi);
    crea_arco(grafo, 0, 4, num_nodi);

    crea_arco(grafo, 1, 0, num_nodi);
    crea_arco(grafo, 1, 2, num_nodi);

    crea_arco(grafo, 2, 1, num_nodi);
    crea_arco(grafo, 2, 3, num_nodi);

    crea_arco(grafo, 4, 0, num_nodi);
    crea_arco(grafo, 4, 1, num_nodi);
    crea_arco(grafo, 4, 5, num_nodi);
    crea_arco(grafo, 4, 6, num_nodi);

    crea_arco(grafo, 5, 1, num_nodi);

    crea_arco(grafo, 6, 7, num_nodi);

    crea_arco(grafo, 8, 9, num_nodi);

    crea_arco(grafo, 9, 8, num_nodi);
    crea_arco(grafo, 9, 10, num_nodi);
}           // modificata
void carica_grafo_test_non_orientato(Citta grafo [], int num_nodi){

    carica_citta_test(grafo);

    //Creazione archi
    crea_arco(grafo, 0, 1, num_nodi);
    crea_arco(grafo, 1, 0, num_nodi);

    crea_arco(grafo, 0, 4, num_nodi);
    crea_arco(grafo, 4, 0, num_nodi);

    crea_arco(grafo, 1, 2, num_nodi);
    crea_arco(grafo, 2, 1, num_nodi);

    crea_arco(grafo, 2, 3, num_nodi);
    crea_arco(grafo, 3, 2, num_nodi);

    crea_arco(grafo, 4, 1, num_nodi);
    crea_arco(grafo, 1, 4, num_nodi);

    crea_arco(grafo, 4, 5, num_nodi);
    crea_arco(grafo, 5, 4, num_nodi);

    crea_arco(grafo, 4, 6, num_nodi);
    crea_arco(grafo, 6, 4, num_nodi);

    crea_arco(grafo, 5, 1, num_nodi);
    crea_arco(grafo, 1, 5, num_nodi);

    crea_arco(grafo, 6, 7, num_nodi);
    crea_arco(grafo, 7, 6, num_nodi);

    crea_arco(grafo, 8, 9, num_nodi);
    crea_arco(grafo, 9, 8, num_nodi);

    crea_arco(grafo, 9, 10, num_nodi);
    crea_arco(grafo, 10, 9, num_nodi);
}
void aggiungi_nodo(Citta grafo[], int *num_nodi){

    /* Inserimento dati nodo */
    getchar();
    printf("\nNome:\n");
    scanf("%[^\n]s", grafo[*num_nodi].nome);
    getchar();

    printf("\nNazione:\n");
    scanf("%[^\n]s", grafo[*num_nodi].nazione);
    getchar();

    printf("\nAbitanti:\n");
    scanf("%d", &grafo[*num_nodi].abitanti);
    getchar();

    grafo[*num_nodi].lista_adj = NULL;

    *num_nodi += 1;
}
void crea_arco(Citta grafo[], int id_coda, int id_testa, int num_nodi){
    Node *appn_next = grafo[id_coda].lista_adj;
    Node *appn_prev = grafo[id_coda].lista_adj;

    if(appn_next == NULL){                                                   // In caso di lista adiecenze nulla
        grafo[id_coda].lista_adj = (Node *) malloc(sizeof(Node));                           // Alloccamento dinamico di memoria
        grafo[id_coda].lista_adj->vertex_id = id_testa;                                     // Assegnamento id al nodo
        grafo[id_coda].lista_adj->link = NULL;
    }
    else{
        appn_next = appn_next->link;
        while (appn_next != NULL){                                           // Itera fino ad ottenere la cella di memoria nulla della lista
            appn_next = appn_next->link;
            appn_prev = appn_prev->link;
        }
        appn_next = (Node *) malloc(sizeof(Node));                           // Alloccamento dinamico di memoria
        appn_next->vertex_id = id_testa;                                     // Assegnamento id al nodo
        appn_next->link = NULL;
        appn_prev->link = appn_next;                                         // Arco orientato adiacente
    }
}
void stampa_lista_adiacenze(Citta grafo[], int num_nodi){
    int i = 0, j = 1;
    Node *appn = grafo[i].lista_adj;

    for(i = 0; i < num_nodi; i++){          // Nodo di partenza
        printf("\n%d: %s ",i , grafo[i].nome);

        if(i == j){                         // Aggiornamento lista adiacenze
            j++;
            appn = grafo[i].lista_adj;
        }

        while(appn != NULL){
            printf("-> %s ", grafo[appn->vertex_id].nome);
            appn = appn->link;
        }
    }
}
void DFS(Citta grafo[], int visited[], int start_id){
    Node *tmp = grafo[start_id].lista_adj;  // tmp punta al campo lista_adj di grafo[id]
    int id_next;
    visited[start_id] = 1;                  // visita nodo id e marca id come visitato

    printf("%s ", grafo[start_id].nome);

    while (tmp != NULL){
        id_next = tmp->vertex_id;
        if(visited[id_next] != 1)
            DFS(grafo, visited, id_next);

        tmp = tmp->link;
    }
}
void BFS(Citta grafo[], int visited[], int start_id){
    visited[start_id] = 1;
    int i = 0;
    Node *tmp = NULL;

    /* Coda */
    Queue C;
    C.cont = 0;
    C.back = NULL;
    C.front = NULL;
    pushQueue(&C, start_id);

    while(isEmptyQueue(&C) == false){
        i = popQueue(&C);
        tmp = grafo[i].lista_adj;

        while(tmp != NULL){
            if(visited[tmp->vertex_id] != 1){
                pushQueue(&C, tmp->vertex_id);
                visited[tmp->vertex_id] = 1;
            }
            tmp = tmp->link;
        }
        printf("%s ", grafo[i].nome);
    }
}
void cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi){
    Node *appn = grafo[id_coda].lista_adj;

    if(id_testa < num_nodi) {
        if (appn->vertex_id == id_testa) {                                  // In caso di primo nodo da cancellare
            grafo[id_coda].lista_adj = grafo[id_coda].lista_adj->link;
        } else if (appn->link->vertex_id == id_testa) {
            grafo[id_coda].lista_adj->link = grafo[id_coda].lista_adj->link->link;
        } else {
            while (appn->link->link != NULL && appn->link->vertex_id != id_testa) {
                appn = appn->link;
            }
            if (appn->link->vertex_id == id_testa)
                appn->link = appn->link->link;
            else
                printf("\n%s non e\' presente nella lista adiacenze di %s", grafo[id_testa].nome, grafo[id_coda].nome);
        }
    }
}
void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi){
    Node *appn = grafo[id_coda].lista_adj;

    if(id_testa < num_nodi) {
        if (appn->vertex_id == id_testa) {                                  // In caso di primo nodo da cancellare
            grafo[id_coda].lista_adj = grafo[id_coda].lista_adj->link;
        } else if (appn->link->vertex_id == id_testa) {
            grafo[id_coda].lista_adj->link = grafo[id_coda].lista_adj->link->link;
        } else {
            while (appn->link->link != NULL && appn->link->vertex_id != id_testa) {
                appn = appn->link;
            }
            if (appn->link->vertex_id == id_testa)
                appn->link = appn->link->link;
            else
                printf("\n%s non e\' presente nella lista adiacenze di %s", grafo[id_testa].nome, grafo[id_coda].nome);
        }
    }

    if(id_coda < num_nodi) {
        if (appn->vertex_id == id_testa) {                                  // In caso di primo nodo da cancellare
            grafo[id_testa].lista_adj = grafo[id_testa].lista_adj->link;
        } else if (appn->link->vertex_id == id_coda) {
            grafo[id_testa].lista_adj->link = grafo[id_testa].lista_adj->link->link;
        } else {
            while (appn->link->link != NULL && appn->link->vertex_id != id_coda) {
                appn = appn->link;
            }
            if (appn->link->vertex_id == id_coda)
                appn->link = appn->link->link;
            else
                printf("\n%s non e\' presente nella lista adiacenze di %s", grafo[id_coda].nome, grafo[id_testa].nome);
        }
    }
}
void componenti_connesse(Citta grafo[], int visited[], int num_nodi){
    int i = 0, j = 1;

    for(i = 0; i < num_nodi; i++){
        if(visited[i] == 0){          // Nodo non visitato
            printf("\n#%d\n", j);
            DFS(grafo, visited, i);   // Visito i nodi connessi
            printf("\n");
            j++;
        }
    }
}


/* Funzioni per la gestione della Coda */
_Bool isEmptyQueue(Queue *p){
    if(p->back == NULL && p->front == NULL)      // Coda vuota
        return true;
    else
        return false;
}
_Bool isFullQueue(Queue *p){
    if (p->cont >= MAX_VERTICI)
        return true;
    else
        return false;
}
void pushQueue(Queue *p, int val){
    Node *new_node = NULL;

    if(isFullQueue(p))                      // In caso di coda piena
        printf("\nErrore Overflow");
    else{                                    // In caso di coda vuota
        new_node = (Node *) malloc(sizeof(Node));
        new_node->vertex_id = val;           // Ordine
        new_node->link = NULL;               // Link vuoto

        if (isEmptyQueue(p)){                // In caso di coda vuota
            p->front = new_node;             // front punta al primo elemento della coda
            p->back = new_node;              // back punta all'ultimo elemento della coda
        }
        else{                                // In caso di coda piena
            p->back->link = new_node;        //
            p->back = new_node;              //
        }
        p->cont += 1;                        // Incremento conteggio
    }
}
int popQueue(Queue *p){
    int val;
    Node *temp = NULL;

    if (isEmptyQueue(p)){                       // In caso di coda vuota
        printf("\nErrore Underflow");
        val = -1;                               // val è una variabile temporanea di tipo Type
    }
    else{
        temp = p->front;                        // temp è un puntatore temporaneo
        val = p->front->vertex_id;

        if (p->cont == 1){
            p->back = NULL;
            p->front = NULL;
        }
        else
            p->front = p->front->link;

        p->cont -= 1;                           // Decremento conteggio
        free(temp);
    }
    return val;
}