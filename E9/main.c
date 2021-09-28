#include "functions.h"

int main(){
    Citta grafo[MAX_VERTICI];
    int num_nodi = 0;
    int visited[MAX_VERTICI];

    int operazione = 0, i = 0;

    for(i = 0; i < MAX_VERTICI; i++){
        visited[i] = 0;
    }

    /** Città esempio **/
    printf("\nCaricare citta\' esempio?");
    printf("\n[1] - Carica grafo test orientato");
    printf("\n[2] - Carica grafo test non orientato");
    printf("\n[0] - Non caricare l'esempio");
    printf("\n");
    scanf("%d", &operazione);
    if(operazione == 1){
        num_nodi = NUM_NODI_TEST;
        carica_grafo_test_orientato(grafo, num_nodi);
        stampa_lista_adiacenze(grafo, num_nodi);
    }
    else if(operazione == 2){
        num_nodi = NUM_NODI_TEST;
        carica_grafo_test_non_orientato(grafo, num_nodi);
        stampa_lista_adiacenze(grafo, num_nodi);
    }

    /** Menu **/
    do{
        /** Lista comandi **/
        printf("\n");
        printf("\n[1] - Aggiungi nodo");
        printf("\n[2] - Crea arco");
        printf("\n[3] - Stampa lista adiacenze");
        printf("\n[4] - Stampa la visita in profondita\'");
        printf("\n[5] - Stampa la visita in ampiezza");
        printf("\n[6] - Cancella arco orientato");
        printf("\n[7] - Cancella arco non orientato");
        printf("\n[8] - Componenti connesse");
        printf("\n[0] - Esci");
        printf("\n");
        scanf("%d", &operazione);

        for(i = 0; i < MAX_VERTICI; i++){
            visited[i] = 0;
        }

        switch(operazione) {

            /** Aggiungi nodo **/
            case 1:
                aggiungi_nodo(grafo, &num_nodi);    // aggiunge una città nel grafo chiedendo i dati all’utente
                break;

            /** Crea arco **/
            case 2:
                case_2(grafo, num_nodi);
                break;

            /** Stampa lista adiacenze **/
            case 3:
                stampa_lista_adiacenze(grafo, num_nodi);    // non funziona
                break;

            /** Stampa la visita in profondita' **/
            case 4:
                case_4(grafo, visited);
                break;

            /** Stampa la visita in ampiezza **/
            case 5:
                case_5(grafo, visited);
                break;

            /** Cancella arco orientato **/
            case 6:
                case_6(grafo, visited, num_nodi);
                break;

            /** Cancella arco non orientato **/
            case 7:
                case_7(grafo,visited, num_nodi);
                break;

            /** Componenti connesse **/
            case 8:
                componenti_connesse(grafo, visited, num_nodi);
                break;

            /** Esci **/
            case 0:
            default:
                break;
        }
    }while(operazione != 0);

    return 0;
}