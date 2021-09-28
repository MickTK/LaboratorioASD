//
// Created by Michele Melis on 07/04/2020.
//

#ifndef E4_FUNCTIONS_H
#define E4_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Esercizio 4_1: Funzione insuccesso **/
int * insuccesso(char pat[]);

/** Esercizio 4_2: Knuth, Morris and Pratt **/
int KMP_match (char stringa[], char pat[]);

/** Esercizio 4_3: KMP, rotazioni cicliche**/
int KMP_match_mod (char stringa[], char pat[]);

#endif //E4_FUNCTIONS_H