//
// Created by Michele Melis on 14/04/2020.
//

#ifndef E5_FUNCTIONS_H
#define E5_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DIM_CODA 10   // modificare a piacimento
#define DIM_STACK 10  // modificare a piacimento
#define DIM_STRING 50

typedef struct{
    char articolo[DIM_STRING];
    double prezzo;
    char destinatario[DIM_STRING];
}Ordine;

struct node{
    Ordine data;
    struct node* link;
};
typedef struct node Node;

typedef struct{
    Node* front;
    Node* back;
    int cont;
}Queue;

typedef struct
{
    Node* top;
    int cont;
}Stack;

//prototipi funzioni per la gestione della Coda
_Bool isEmptyQueue(Queue *p);
_Bool isFullQueue(Queue *p);
void pushQueue(Queue *p, Ordine val);
Ordine popQueue(Queue *p);
void printQueue(Queue *queue);

//prototipi funzioni per la gestione dello Stack
_Bool isEmptyStack(Stack *p);
_Bool isFullStack(Stack *p);
void pushStack(Stack *p, Ordine val);
Ordine popStack(Stack *p);
void printStack(Stack *stack);

#endif //E5_FUNCTIONS_H
