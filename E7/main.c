#include "functions.h"

int main(){
    //inizializzazione pronto soccorso
    ProntoSoccorso ps;
    ps.numeroB = ps.numeroG = ps.numeroV = ps.numeroR = 0;

    //inizializzazione della Coda con priorita'
    Paziente codaPrio[DIM_HEAP];
    int dim_coda = 0;

    int input = 1;

    while(input != 0){
        do{
            printf("\n[1] - Inserimento nuovo paziente in coda\n");
            printf("[2] - Rimuovi paziente dalla coda\n");
            printf("[3] - Visualizza coda\n");
            printf("[0] - Termina programma\n");
            scanf("%d", &input);
            if(input < 0 || input > 3)
                printf("\nOperazione non valida\n\n");
        }while(input < 0 || input > 3);
        switch(input){
            case 1:
                insertHeap(codaPrio, nuovoPaziente(&ps), &dim_coda);
                break;
            case 2:
                deleteHeap(codaPrio, &dim_coda);
                dim_coda--;
                break;
            case 3:
                printHeap(codaPrio, dim_coda);
                break;
            default:
                break;
        }

    }
    return 0;
}