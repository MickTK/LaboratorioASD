#include "functions.h"

int main(){
    //Creazione di una PLAYLIST. Utilizzare e riempire questa playlist
    PlayList p;
    strcpy(p.name, "My favourite songs");
    p.top = NULL;
    //
    int inputNum = 0;
    char title[DIM_TITLE];
    Song* canzone_corrente = NULL;

    //altre chiamate e istruzioni per testare il funzionamento delle funzioni create
    do{              /** Menu **/
        printf("\n");
        printf("[1] Aggiungi canzone\n");
        printf("[2] Trova canzone\n");
        printf("[3] Modifica canzone\n");
        printf("[4] Cancella canzone\n");
        printf("[5] Visualizza lista canzoni\n");
        printf("[6] Modalita\' scorrimento\n");
        printf("[0] Esci\n");
        scanf("%d", &inputNum);
        switch(inputNum){
            case 1:                          // Aggiungi canzone
            insertSong(&p, acquireSong());
                break;
            case 2:                          // Trova canzone
                printf("Nome:\n");
                scanf("%s", title);
                printSong(findSong(&p, title));
                break;
            case 3:                          // Modifica canzone
                printf("Nome canzone da modificare:\n");
                scanf("%s", title);
                modifySong(&p, findSong(&p, title));
                break;
            case 4:                          // Cancella canzone
                printf("Canzone da cancellare:\n");
                scanf("%s", title);
                deleteSong(&p, findSong(&p, title));
                break;
            case 5:                          // Visualizza lista canzoni
                printPlayList(&p);
                break;
            case 6:                          // Modalità scorrimento
                canzone_corrente = p.top;       // Prima canzone della playlist
                if(canzone_corrente != NULL){   // In caso di playlist non vuota
                    printSong(canzone_corrente);

                                     /** Sotto Menu **/
                    do{
                        printf("[1] Indietro\n");
                        printf("[2] Avanti\n");
                        printf("[0] Esci\n");
                        scanf("%d", &inputNum);
                        switch(inputNum){
                            case 1: // Indietro
                                if(canzone_corrente->prev != NULL){
                                    canzone_corrente = prevSong(canzone_corrente);
                                    printSong(canzone_corrente);
                                }
                                else
                                    printf("Sei in testa alla playlist\n");
                                break;
                            case 2: // Avanti
                                if(canzone_corrente->next != NULL){
                                    canzone_corrente = nextSong(canzone_corrente);
                                    printSong(canzone_corrente);
                                }
                                else
                                    printf("Sei in coda alla playlist\n");
                                break;
                            default:
                                break;
                        }
                    }while(inputNum != 0);
                }
                inputNum = 1;              // Reset variabile menu
                break;
            default:
                break;
        }
    }while(inputNum != 0);

    return 0;
}