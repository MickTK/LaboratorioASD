#include "functions.h"

int main() {
    /** Variabili e vettori **/
    int *A = NULL;
    int i = 0;
    clock_t start, end;
    double t;
    int esercizio = 0;
    Ricetta *ricetta = NULL;
    int input = 0, n = 0;
    _Bool flag = true;


    /** Menu **/
    do{
        printf("\nNumero dell'esercizio: ");
        scanf("%d", &esercizio);                                  // Immissione numero dell'esercizio
    }while(esercizio < 1 || esercizio > 5);
    switch(esercizio){
        case 1:

            /** Esercizio 1_1: Selection Sort iterativo **/
            srand(time(NULL));                                    // Seed generazione casuale
            start = clock();
            A = genera_array(N, ORDINATO);                        // Generazione vettore
            for(i = 0; i < N; i++){                               // Stampa a video i risultati
                printf("\n%d", A[i]);
            }
            end = clock();
            t = ((double) (end - start)) / CLOCKS_PER_SEC;        // Calcolo tempo di esecuzione
            printf("\nTempo impiegato: %lf secondi", t);

            break;
        case 2:

            /** Esercizio 1_2: difficoltà++ **/
            do{
                printf("\nComandi:");                             // Operazioni
                printf("\n[1] - Aggiungi ricetta");
                printf("\n[2] - Visualizza ricette");
                printf("\n[0] - Esci\n");
                scanf("%d", &input);                              // Immissione input da parte dell'utente
                switch (input) {
                    case 0:                                       // Termina l'esecuzione
                        flag = false;
                        break;
                    case 1:                                       // Aggiungi ricetta
                        n++;                                      // Incremento numero di ricette
                        ricetta = allocca_memoria(ricetta, n);    // Alloccazione dinamica nuova cella di memoria
                        nuova_ricetta(ricetta, n);                // Inserimento nuova ricetta
                        selection_sort_ricetta(ricetta, n);       // Ordinamento ricette
                        break;
                    case 2:                                       // Visualizza ricette
                        stampa_ricette(ricetta, n);
                        break;
                    default:
                        break;
                }
            }while(flag);

            break;
        case 3:

            /** Esercizio 1_3: Ricerca lineare **/
            srand(time(NULL));
            start = clock();
            A = genera_array(N, INV_ORDINATO);                    // Generazione array
            selection_sort(A, N);                                 // Riordina i valori
            printf("\nNumero da cercare:\n");
            scanf("%d", &i);                                      // Immissione input da parte dell'utente
            i = ricercaBanale(A, i, N);                           // Ricerca numero nel vettore
            if(i != -1)
                printf("\nIl numero cercato si trova nella cella con indice: %d", i);
            else
                printf("\nIl numero cercato non è presente nel vettore");
            printf("\n");
            for(i = 0; i < N; i++){                               // Stampa a video i risultati
                printf("\n%d", A[i]);
            }
            printf("\n");
            end = clock();
            t = ((double) (end - start)) / CLOCKS_PER_SEC;        // Calcolo tempo di esecuzione
            printf("\nTempo impiegato: %lf secondi", t);

            break;
        case 4:

            /** Esercizio 1_4: Ricerca binaria iterativa **/
            srand(time(NULL));
            start = clock();
            A = genera_array(N, INV_ORDINATO);                    // Genera array
            selection_sort(A, N);                                 // Riordina i valori
            printf("\nNumero da cercare:\n");
            scanf("%d", &i);                                      // Immissione input da parte dell'utente
            i = ricercaBinariaIter(A, i, N);                      // Ricerca numero nel vettore
            if(i != -1)
                printf("\nIl numero cercato si trova nella cella con indice: %d", i);
            else
                printf("\nIl numero cercato non è presente nel vettore");
            printf("\n");
            printf("\n[indice] - valore");
            for(i = 0; i < N; i++){                               // Stampa a video i risultati
                printf("\n[%d] - %d", i, A[i]);
            }
            printf("\n");
            end = clock();
            t = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("\nTempo impiegato: %lf secondi", t);          // Calcolo tempo di esecuzione

            break;
        case 5:

            /** Esercizio 1_5: Ricerca binaria ricorsiva **/
            srand(time(NULL));
            start = clock();
            A = genera_array(N, INV_ORDINATO);                    // Generazione array
            selection_sort(A, N);                                 // Riordina il valori
            printf("\nNumero da cercare:\n");
            scanf("%d", &i);                                      // Immissione input da parte dell'utente
            i = ricBinRic(A, i, 0, N);
            if(i != -1)
                printf("\nIl numero cercato si trova nella cella con indice: %d", i);
            else
                printf("\nIl numero cercato non è presente nel vettore");
            printf("\n");
            printf("\n[indice] - valore");
            for(i = 0; i < N; i++){                               // Stampa a video i risultati
                printf("\n[%d] - %d", i, A[i]);
            }
            printf("\n");
            end = clock();
            t = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("\nTempo impiegato: %lf secondi", t);


            break;
    }
    return 0;
}