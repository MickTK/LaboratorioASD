//
// Created by Michele Melis on 30/04/2020.
//

#include "functions.h"

Paziente nuovoPaziente(ProntoSoccorso *ps){
    Paziente p;

    getchar();
    printf("\nNome paziente -> ");
    scanf("%[^\n]s", p.nome);
    getchar();

    do{
        printf("\nCodice paziente (0 = bianco, 1 = verde, 2 = giallo, 3 = rosso)-> ");
        scanf("%u", &p.codice);
        getchar();

        if(p.codice < BIANCO || p.codice > ROSSO)
            printf("\nCodice non valido");
    }while(p.codice < BIANCO || p.codice > ROSSO);

    if(p.codice == BIANCO){
        ps->numeroB++;
        p.ordine = ps->numeroB;
    }
    else if(p.codice == GIALLO)
    {
        ps->numeroG++;
        p.ordine = ps->numeroG;

    }
    else if (p.codice == VERDE)
    {
        ps->numeroV++;
        p.ordine = ps->numeroV;
    }
    else
    {
        ps->numeroR++;
        p.ordine = ps->numeroR;
    }

    return p;
}

int priorita(Paziente p1, Paziente p2){
    if(p1.codice > p2.codice)
        return 1;
    else if (p1.codice < p2.codice)
        return 2;
    else if (p1.codice == p2.codice){
        if(p1.ordine <= p2.ordine)
            return 1;
        else if (p1.codice > p2.codice)
            return 2;
    }
}

void insertHeap(Paziente heap[], Paziente item, int *n){
    int i;

    // inserisce un nuovo item in un heap di n elementi
    if (*n == DIM_HEAP-1){
        printf("L\'heap e\' pieno\n");
     return;
    }
    *n = *n + 1;
    i = *n;
    while (i != 1 && priorita(item, heap[i/2]) == 1){
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = item;
}

Paziente deleteHeap(Paziente heap[], int *n){
    Paziente item, temp;
    int padre, figlio;

    // cancella e restituisce l’elemento radice in un heap di n elementi
    item = heap[1];
    temp = heap[*n];
    n = n-1;
    padre = 1;
    figlio = 2;

    while(figlio <= *n){
        if (figlio < *n && priorita(heap[figlio], heap[figlio+1]) == 2){
            figlio = figlio+1;
        }
        if(priorita(temp, heap[figlio]) == 1){
            break;
        }

        heap[padre] = heap[figlio];
        padre = figlio;
        figlio = 2 * figlio;
    }

    heap[padre] = temp;
    return item;
}

void printHeap(Paziente heap[], int dim_coda){
    int i = 0;

    for(i = 1; i <= dim_coda; i++){
        printf("Paziente: %d\n", i);
        switch(heap[i].codice){
            case BIANCO:
                printf("  Codice: Bianco\n");
                break;
            case VERDE:
                printf("  Codice: Verde\n");
                break;
            case GIALLO:
                printf("  Codice: Giallo\n");
                break;
            case ROSSO:
                printf("  Codice: Rosso\n");
                break;
            default:
                break;
        }
        printf("    Nome: %s\n", heap[i].nome);
    }
}