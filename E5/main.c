#include "functions.h"

int main(){
    //dichiarazione e inizializzazione della Coda
    Queue queue;
    queue.front = NULL;
    queue.back = NULL;
    queue.cont = 0;

    //dichiarazione e inizializzazione dello Stack
    Stack stack;
    stack.top = NULL;
    stack.cont = 0;

    // Altro
    Ordine ordine;
    int input, i, j = 0;
    _Bool spedizione_in_corso = false;
    char destinatario[DIM_STRING];

    /** Init **/
    printf("\nInserisci il tuo nome per effettuare il login:\n");
    scanf("%[^\n]s", destinatario);
    getchar();
    printf("\nBenvenuto %s\n", destinatario);

    /** Menu **/
    do{
        printf("\n");
        printf("\nScegli l'operazione da effettuare");
        printf("\n[1] - Nuovo ordine");
        printf("\n[2] - Avvia spedizione");
        printf("\n[3] - Controllo ricezione ordini");
        printf("\n[4] - Stampa ordini carrello");
        printf("\n[5] - Stampa ordini in arrivo");
        printf("\n[0] - Esci");
        printf("\n");
        scanf("%d", &input);

        switch(input){

            /** Nuovo ordine **/
            case 1:
                if (queue.cont < DIM_CODA) {
                    printf("\nNome articolo:\n");
                    getchar();
                    scanf("%[^\n]s", ordine.articolo);

                    printf("\nPrezzo articolo:\n");
                    scanf("%lg", &ordine.prezzo);

                    strcpy(ordine.destinatario, destinatario);

                    printf("\nOrdini nel carrello:");
                    pushQueue(&queue, ordine);  // Inserire un nuovo ordine in coda
                    printQueue(&queue);         // Stampa a video la coda
                } else
                    printf("\nLa coda è piena, procedi con la spedizione");
                break;

            /** Avvia spedizione **/
            case 2:
                if(spedizione_in_corso == false && queue.cont > 0) {
                    while(queue.cont > 0)
                        pushStack(&stack, popQueue(&queue));
                    printf("\nSpedizione avviata, attendere l'arrivo dei prodotti");
                    spedizione_in_corso = true;
                } else
                    printf("\nUna spedizione e\' gia\' in corso, attendi l'arrivo");
                break;

            /** Controllo ricezione ordini **/
            case 3:
                if (spedizione_in_corso == true) {
                    printf("\nOrdine ricevuto\n");
                    printStack(&stack);
                    while(stack.cont > 0)
                        popStack(&stack);
                    spedizione_in_corso = false;
                } else
                    printf("\nNon e\' stato effettuato nessun ordine");
                break;

            /** Stampa ordini carrello **/
            case 4:
                if (queue.cont > 0)
                    printQueue(&queue);
                else
                    printf("\nCarrello vuoto");
                break;

            /** Stampa ordini in arrivo **/
            case 5:
                if (stack.cont > 0)
                    printStack(&stack);
                else
                    printf("\nNessun ordine in arrivo");
                break;

            /** Esci **/
            case 0:
            default:
                break;
        }
    }while(input != 0);

    return 0;
}