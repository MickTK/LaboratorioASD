//
// Created by Michele Melis on 31/03/2020.
//

#include "functions.h"

// Funzione che riempie (con i valori dell'esempio presenti nelle slide della lezione 3) la matrice classica passata in ingresso
void fill_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    matrix[1][0] = 71;
    matrix[2][14] = 99;
    matrix[3][11] = 53;
    matrix[4][7] = 95;
    matrix[6][14] = 39;
    matrix[8][1] = 27;
    matrix[9][14] = 14;
}

// Funzione che stampa a video una matrice classica
void print_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    int i, j = 0;

    printf("\n");
    for(i=0; i<numr; i++)
    {
        for(j=0; j<numc; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Funzione che implementa la ricerca di un elemento (numric) in una matrice classica
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric)
{
    int i, j = 0;
    for(i=0; i<=numr; i++){
        for(j=0; j<=numc; j++){
            if(matrix[i][j] == numric){
                printf("Elemento %d trovato in posizione (%d, %d).\n", numric, i, j);
                return;
            }
        }
    }
    printf("Elemento non trovato.\n");
}

/* MM Functions */
Tripla * input_matrice(int numr, int numc){
    int input = 0;
    Tripla *matrice = NULL;
    Tripla app;
    int i = 0, j = 0;

    printf("\nQuanti valori vuoi inserire?\n");
    scanf("%d", &input);

    matrice = (Tripla *) malloc(sizeof(Tripla) * (input + 1));  // Alloccazione dinamica
    matrice[0].riga = numr;
    matrice[0].colonna = numc;
    matrice[0].valore = input;

    /* Riempimento matrice */
    printf("\nInserisci tutti i dati");
    for(i = 1; i <= matrice[0].valore; i++){
        printf("\n[%d di %d]", i, matrice[0].valore);   // Numero inserimento
        printf("\nRiga: ");
        scanf("%d", &matrice[i].riga);
        printf("\nColonna: ");
        scanf("%d", &matrice[i].colonna);
        printf("\nValore: ");
        scanf("%d", &matrice[i].valore);
    }

    /* Ordinamento */
    for(i = 1; i <= matrice[0].valore; i++){
        for(j = 1; j <= matrice[0].valore; j++){
            /* Ordinamento per riga */
            if(matrice[i].riga > matrice[j].riga){
                app.riga = matrice[i].riga;
                app.colonna = matrice[i].colonna;
                app.valore = matrice[i].valore;

                matrice[i].riga = matrice[j].riga;
                matrice[i].colonna = matrice[j].colonna;
                matrice[i].valore = matrice[j].valore;

                matrice[j].riga = app.riga;
                matrice[j].colonna = app.colonna;
                matrice[j].valore = app.valore;
            }
            /* Ordinamento per colonna */
            else if(matrice[i].riga == matrice[j].riga &&
                    matrice[i].colonna > matrice[j].colonna){
                app.riga = matrice[i].riga;
                app.colonna = matrice[i].colonna;
                app.valore = matrice[i].valore;

                matrice[i].riga = matrice[j].riga;
                matrice[i].colonna = matrice[j].colonna;
                matrice[i].valore = matrice[j].valore;

                matrice[j].riga = app.riga;
                matrice[j].colonna = app.colonna;
                matrice[j].valore = app.valore;
            }
        }
    }



    return matrice;
}
void riempimento_matrice_sparsa(int matrix[][NUMC], Tripla matrice_tripla[]){
    int i = 0;

    for(i = 0; i < matrice_tripla[0].valore; i++){
        matrix[matrice_tripla[i].riga-1][matrice_tripla[i].colonna-1] = matrice_tripla[i].valore;
    }

}
void trasp_rapida(Tripla *a, Tripla *b){
    int num_col = 0, num_val = 0;
    int i = 0, cur_pos = 0;
    int *termini_riga = NULL, *pos_iniziale = NULL;

    num_col = a[0].colonna;
    num_val = a[0].valore;
    b[0].riga = num_col;
    b[0].colonna = a[0].riga;
    b[0].valore = num_val;

    /* Alloccazione dinamica di memoria */
    termini_riga = (int *) malloc(sizeof(int) * a[0].colonna);
    pos_iniziale = (int *) malloc(sizeof(int) * a[0].colonna);

    if(num_val > 0) {

        /* Creazione termini_riga */
        for (i = 0; i <= num_col - 1; i++)
            termini_riga[i] = 0;
        for (i = 0; i <= num_val; i++)
            termini_riga[a[i].colonna] = termini_riga[a[i].colonna] + 1;

        /* Creazione pos_iniziale */
        pos_iniziale[0] = 1;
        for (i = 1; i <= num_col-1; i++)
        pos_iniziale[i] = pos_iniziale[i-1] + termini_riga[i-1];

        /* Trasposizione */
        for (i = 1; i <= num_val; i++){
            cur_pos = pos_iniziale[a[i].colonna];
            pos_iniziale[a[i].colonna] = pos_iniziale[a[i].colonna] + 1;
            b[cur_pos].riga = a[i].colonna;
            b[cur_pos].colonna = a[i].riga;
            b[cur_pos].valore = a[i].valore;
        }

    }
}