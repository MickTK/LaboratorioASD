#include "functions.h"

int main(){
    Nodo* parcheggio[NUM_PIANI];
    int i = 0, operazione;
    char targa[MAX_TARGA];
    Nodo *nodo_temp = NULL;

    for(i = 0; i < NUM_PIANI; i++)
        parcheggio[i] = NULL;


    /** Menu **/
    do{
        /** Lista comandi **/
        printf("\n");
        printf("\n[1] - Aggiungi auto al parcheggio");
        printf("\n[2] - Cerca auto nel parcheggio");
        printf("\n[3] - Rimuovi auto dal parcheggio");
        printf("\n[4] - Stampa parcheggio");
        printf("\n[5] - Aggiungi auto test");
        printf("\n[0] - Esci");
        printf("\n");
        scanf("%d", &operazione);
        getchar();

        switch(operazione) {

            /** Aggiungi auto al parcheggio **/
            case 1:
                inserisci_auto(parcheggio, acquisisci_auto());
                printf("\nAuto inserita con successo\n");
                break;

            /** Cerca auto nel parcheggio **/
            case 2:
                printf("\nInserisci targa auto:\n");
                scanf("%s", targa);
                getchar();
                nodo_temp = ricerca_auto(parcheggio, targa);
                if(nodo_temp != NULL){
                    stampa_piano(parcheggio, hash_function(targa));
                    printf("\nAuto parcheggiata alle %d:%d.", nodo_temp->info.ora, nodo_temp->info.min);
                }
                else
                    printf("\nAuto non presente nel parcheggio\n");
                break;

            /** Rimuovi auto dal parcheggio **/
            case 3:
                printf("\nInserisci targa auto:\n");
                scanf("%s", targa);
                getchar();
                if(ricerca_auto(parcheggio, targa) != NULL){
                    elimina_auto(parcheggio, targa);
                    printf("\nAuto rimossa con successo\n");
                }
                else
                    printf("\nAuto non presente nel parcheggio\n");
                break;

            /** Stampa parcheggio **/
            case 4:
                stampa_parcheggio(parcheggio);
                break;

            /** Aggiungi auto test **/
            case 5:
                carica_auto_test(parcheggio);
                printf("\nAuto aggiunte con successo\n");
                break;

            /** Esci **/
            case 0:
            default:
                break;
        }

    }while(operazione != 0);

    return 0;
}