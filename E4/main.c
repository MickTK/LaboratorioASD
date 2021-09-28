#include "functions.h"

int main() {
    /** Variabili e vettori **/
    int esercizio = 0;
    char stringa[] = "abcde";
    char pat[] = "de";                                         // Pattern
    int *insucc = NULL;

    /** Menu **/
    do{
        printf("\nNumero dell'esercizio: ");
        scanf("%d", &esercizio);                                  // Immissione numero dell'esercizio
    }while(esercizio < 1 || esercizio > 3);
    switch(esercizio){

        /** Esercizio 4_1: Funzione insuccesso **/
        case 1:
            insucc = insuccesso(pat);
            break;


        /** Esercizio 4_2: Knuth, Morris and Pratt **/
        case 2:
            printf("\nPat index: %d", KMP_match(stringa, pat));
            break;

        /** Esercizio 4_3: KMP, rotazioni cicliche**/
        case 3:
            KMP_match_mod(stringa, pat);
            break;

        default:
            break;
    }
    return 0;
}