#include "functions.h"

int main(){
    /** Variabili e vettori **/
    char str[DIM_NOME];
    int *A;
    clock_t start, end;
    double t;
    int esercizio, inputNum = 0, nHotel = 0, i = 0;
    Hotel *B = NULL;

    /** Menu **/
    do{
        printf("\nNumero dell'esercizio: ");
        scanf("%d", &esercizio);                                  // Immissione numero dell'esercizio
    }while(esercizio < 1 || esercizio > 3);
    switch(esercizio){

        /** Esercizio 2_1: Selection Sort ricorsivo **/
        case 1:
            A = genera_array(N, CASUALE);
            for(i = 0; i < N; i++){
                printf("\n%d", A[i]);
            }
            start = clock();
            selectionSortRec(A, N, 0);
            end = clock();
            printf("\nArray ordinato:", t);
            for(i = 0; i < N; i++){
                printf("\n%d", A[i]);
            }
            t = ((double) (end - start)) / CLOCKS_PER_SEC;        // Calcolo del tempo di esecuzione
            printf("\nTempo impiegato: %lf secondi", t);
            break;

        /** Esercizio 2_2 : Ordinamenti a confronto **/
        case 2:
            A = genera_array(N, INV_ORDINATO);                  // Alloccazione dinamica di memoria al puntatore
            start = clock();
            selection_sort(A, N);
            end = clock();
            t = ((double) (end - start)) / CLOCKS_PER_SEC;        // Calcolo del tempo di esecuzione
            print_confr_scambi('i');
            printf("\nTempo impiegato: %lf secondi", t);

            A = genera_array(N, INV_ORDINATO);                  // Alloccazione dinamica di memoria al puntatore
            start = clock();
            selectionSortRec(A, N, 0);
            end = clock();
            t = ((double) (end - start)) / CLOCKS_PER_SEC;        // Calcolo del tempo di esecuzione
            print_confr_scambi('r');
            printf("\nTempo impiegato: %lf secondi", t);
            break;

        /** Esercizio 2_3 : ancora Ricerca Binaria **/
        case 3:
            do{
                printf("\n[1] - Aggiungi Hotel");
                printf("\n[2] - Stampa lista Hotel");
                printf("\n[3] - Ricerca");
                printf("\n[0] - Esci\n");
                scanf("%d", &inputNum);

                if (inputNum == 1) {
                    /* Alloccazione dinamica di memoria al puntatore */
                    if (B == NULL) {
                        nHotel++;
                        B = (Hotel *) malloc(sizeof(Hotel));
                    } else {
                        nHotel++;
                        B = (Hotel *) realloc(B, nHotel * sizeof(Hotel));
                    }

                    getchar();
                    printf("\nNome:\n");
                    scanf("%[^\n]s", B[nHotel - 1].nome);
                    getchar();
                    printf("\nPrezzo a notte:\n");
                    scanf("%lg", &B[nHotel - 1].prezzo_notte);
                    printf("\nVoto Hotel:\n");
                    scanf("%d", &B[nHotel - 1].recensione);
                    selection_sort_hotel(B, nHotel);
                }
                else if(inputNum == 2){
                    stampa_lista_hotel(B, nHotel);
                }
                else if(inputNum == 3){
                    getchar();
                    printf("\nNome hotel:\n");
                    scanf("%[^\n]s", str);
                    getchar();
                    i = ricercaBinariaIter_hotel(B, str, nHotel);
                    if(i == -1)
                        printf("\nHotel non trovato");
                    else{
                        printf("\nNome: %s", B[i].nome);
                        printf("\nRecensione: %d", B[i].recensione);
                        printf("\nPrezzo per notte: %g", B[i].prezzo_notte);
                    }
                    printf("\n");
                }
            }while(inputNum != 0);
            break;

        default:
            break;
    }
    return 0;
}