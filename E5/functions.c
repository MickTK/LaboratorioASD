#include "functions.h"

/** Funzioni per la gestione della Coda **/
_Bool isEmptyQueue(Queue *p){
    if(p->back == NULL && p->front == NULL)      // Coda vuota
        return true;
    else
        return false;
}
_Bool isFullQueue(Queue *p){
    if (p->cont >= DIM_CODA)
        return true;
    else
        return false;
}
void pushQueue(Queue *p, Ordine val){
    Node *new_node = NULL;

    if(isFullQueue(p))                      // In caso di coda piena
        printf("\nErrore Overflow");
    else{                                    // In caso di coda vuota
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = val;                // Ordine
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
Ordine popQueue(Queue *p){
    Ordine val;
    Node *temp = NULL;

    if (isEmptyQueue(p)){                       // In caso di coda vuota
        printf("\nErrore Underflow");
        val.prezzo = -1;                        // val è una variabile temporanea di tipo Type
    }
    else{
        temp = p->front;                        // temp è un puntatore temporaneo
        val = p->front->data;

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
void printQueue(Queue *queue){
    int i = 0;
    Node *n = queue->front;

    if(!isEmptyQueue(queue)) {
        for (i = 1; i <= queue->cont; i++) {
            printf("\n    Articolo: %s", n->data.articolo);
            printf("\n      Prezzo: %g", n->data.prezzo);
            printf("\nDestinatario: %s", n->data.destinatario);
            printf("\n");
            n = n->link;
        }
    }
}

/** Funzioni per la gestione dello Stack **/
_Bool isEmptyStack(Stack *p){
    if (p->cont == 0)       // Stack vuoto
        return true;
    else
        return false;
}
_Bool isFullStack(Stack *p){
    if (p->cont >= DIM_STACK)
        return true;
    else
        return false;
}
void pushStack(Stack *p, Ordine val){
    Node *new_node = NULL;

    if(isFullStack(p))
        printf("\nErrore Overflow");
    else{
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = val;
        new_node->link = NULL;

        if(isEmptyStack(p))
            p->top = new_node;
        else{
            new_node->link = p->top;
            p->top = new_node;
        }
        p->cont += 1;
    }
}
Ordine popStack(Stack *p){
    Ordine val;
    Node *temp = NULL;

    if (isEmptyStack(p)){
        printf("\nErrore Underflow");
        val.prezzo = -1;                 // val è una variabile temporanea di tipo Type
    }
    else{
        temp = p->top;                   // temp è un puntatore temporaneo
        val = p->top->data;

        p->top = p->top->link;
        p->cont -= 1;
        free(temp);
    }
    return val;
}
void printStack(Stack *stack){
    int i = 0;
    Node *n = stack->top;

    for(i = 0; i < stack->cont; i++){
        if(n != NULL){
            printf("\n    Articolo: %s", n->data.articolo);
            printf("\n      Prezzo: %.2f", n->data.prezzo);
            printf("\nDestinatario: %s", n->data.destinatario);
            printf("\n");
            n = n->link;
        }
    }
}