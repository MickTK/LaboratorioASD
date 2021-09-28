//
// Created by Michele Melis on 07/04/2020.
//

#include "functions.h"

/** Esercizio 4_1: Funzione insuccesso **/
int * insuccesso(char pat[]){
    int n = (int) strlen(pat);                                    // Lunghezza di pat
    int *insucc = NULL;                                           // Vettore insuccesso
    int i = 0, j = 0;                                             // Variabili per le iterazioni

    insucc = (int *) malloc(sizeof(int) * n);                     // Alloccazione dinamica di memoria al puntatore

    insucc[0] = -1;                                               // Insuccesso dell prima cella

    for(j = 1; j <= n-1; j++){                                    // Analisi dei prefissi
        i = insucc[j-1];                                          // Assegnamento del valore del prefisso a i

        while (pat[j] != pat[i+1] && i >= 0) {                      // Iterazione
            i = insucc[i];
            /* Calcolo insuccesso ultima cella di memoria */
            if (pat[j] == pat[i + 1])
                insucc[j] = i + 1;
            else
                insucc[j] = -1;
        }
    }

    return insucc;
}

/** Esercizio 4_2: Knuth, Morris and Pratt **/
int KMP_match (char stringa[], char pat[]){
    int *insucc = insuccesso(pat);                                // Array insuccesso
    int i = 0, j = 0;                                             // Variabili iterazioni
    int lenS = (int) strlen(stringa);                             // Lunghezza stringa
    int lenP = (int) strlen(pat);                                 // Lunghezza pat

    while (i < lenS && j < lenP) {                                // Itera finchè non si raggiunge la lunghezza di una delle due stringhe
        if (stringa[i] == pat[j]) {                               // In caso di lettere uguali
            i = i + 1;                                            // Incremento
            j = j + 1;                                            // Incremento
        } else if (j == 0)
            i = i + 1;
        else
            j = insucc[j - 1] + 1;
    }

    if (j == lenP)
        return i-lenP;

    else return -1;
}

/** Esercizio 4_3: KMP, rotazioni cicliche**/
int KMP_match_mod (char stringa[], char pat[]){
    int *insucc = insuccesso(pat);                                // Array insuccesso
    int i = 0, j = 0;                                             // Variabili iterazioni
    int lenS = (int) strlen(stringa);                             // Lunghezza stringa
    int lenP = (int) strlen(pat);                                 // Lunghezza pat

    while (i < lenS && j < lenP) {                                // Itera finchè non si raggiunge la lunghezza di una delle due stringhe
        if (stringa[i] == pat[j]) {                               // In caso di lettere uguali
            i = i + 1;                                            // Incremento
            j = j + 1;                                            // Incremento

            /* Mod */
            if(i == lenS)
                i = 0;
            /* End */

        } else if (j == 0)
            i = i + 1;
        else
            j = insucc[j - 1] + 1;
    }

    if (j == lenP)
        return i-lenP;

    else return -1;
}