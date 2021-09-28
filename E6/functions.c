//
// Created by Michele Melis on 21/04/2020.
//

#include "functions.h"

/* ---------------------------------------------
* funzioni da NON modificare
* --------------------------------------------*/
Song* acquireSong()
{
    Song* new_s = (Song*)malloc(sizeof(Song));
    getchar();
    printf("\nInsert title -> ");
    scanf("%[^\n]s", new_s->title);
    getchar();

    printf("Insert genre -> ");
    scanf("%[^\n]s", new_s->genre);
    getchar();

    printf("Insert length -> ");
    scanf("%f", &(new_s->length));
    getchar();

    new_s->prev = NULL;
    new_s->next = NULL;

    return new_s;
}

void printSong(Song* t)
{
    if(t != NULL){
        printf("TITLE    :\t %s \n", t->title);
        printf("GENRE    :\t %s \n", t->genre);
        printf("LENGTH   :\t %.2f \n\n", t->length);
    }
}

/* ---------------------------------------------
* funzioni STUDENTE
* --------------------------------------------*/

//inserisce una canzone (creata con la funzione acquire) nella lista in maniera ordinata
void insertSong(PlayList* pl, Song* s){
    Song *tmp_prev = NULL;
    Song *tmp_next = NULL;

    if (pl->top == NULL)
        pl->top = s;
    else{                    //ricerca della posizione in cui inserire (tmp_prev e tmp_next sono due puntatori d’appoggio)
        tmp_prev = NULL;
        tmp_next = pl->top;
        while (tmp_next != NULL && strcmp(tmp_next->title, s->title) <= 0){ //attenzione al confronto tra stringhe!
            tmp_prev = tmp_next;
            tmp_next = tmp_next->next;
        }                                           //ora conosciamo il nodo a cui appendere il nuovo nodo s
        if (tmp_next == NULL){
            //< gestire il caso di inserimento in coda >
            s->prev = tmp_prev;
            tmp_prev->next = s;
        }
        else if (tmp_prev == NULL){
            //< gestire il caso di inserimento in testa >
            s->next = pl->top;
            pl->top->prev = s;
            pl->top = s;
        }
        else{
            //<gestire il caso di inserimento generico tra due nodi >
            tmp_prev->next = s;
            s->prev = tmp_prev;
            s->next = tmp_next;
            tmp_next->prev = s;
        }
    }
}

//cerca una canzone nella lista (tramite il titolo) e restituisce il suo puntatore
Song* findSong(PlayList* pl, char title[]){
    Song *app = NULL;
    _Bool flag = 1;

    app = pl->top;
    if(app != NULL)
        while(strcasecmp(app->title, title) != 0 && flag == 1){
            if(app->next != NULL){
                app = app->next;
            }
            else
                flag = 0;
        }
    if(strcasecmp(app->title, title) == 0){
        return app;
    }
    else
        printf("La canzone non e\' presente nella playlist\n");
}

//modifica una canzone gia’ presente (trovata tramite la funzione findSong) e la riposiziona nella posizione corretta
void modifySong(PlayList* pl, Song* s){
    getchar();
    printf("\nInsert title -> ");
    scanf("%[^\n]s", s->title);
    getchar();

    printf("Insert genre -> ");
    scanf("%[^\n]s", s->genre);
    getchar();

    printf("Insert length -> ");
    scanf("%f", &(s->length));
    getchar();

    insertSong(pl, s);
}

//elimina una canzone gia’ presente (trovata tramite la funzione findSong) e dealloca l’elemento
void deleteSong(PlayList* pl, Song* s){
    Song *tmp_prev = s->prev;
    Song *tmp_next = s->next;

    if(tmp_prev == NULL && tmp_next == NULL){   // Unica canzone nella playlist
        pl->top = NULL;
    }
    else if(tmp_prev == NULL && tmp_next != NULL){  // Prima canzone della playlist
        pl->top = tmp_next;
        tmp_next->prev = NULL;
    }
    else if(tmp_prev != NULL && tmp_next != NULL){  // Canzone in mezzo alla playlist
        tmp_prev->next = tmp_next;
        tmp_next->prev = tmp_prev;
    }
    else if(tmp_prev != NULL && tmp_next == NULL){  // Ultima canzone della playlist
        tmp_prev->next = NULL;
    }

    free(s);    // Dealloca elemento
}

//stampa l’intera playlist di canzoni
void printPlayList(PlayList* pl){
    Song *app = pl->top;

    if(app != NULL){
        while(app != NULL){

            // stampa
            printf("Titolo: %s\n", app->title);
            printf("Genere: %s\n", app->genre);
            printf("Durata: %.2f\n", app->length);
            printf("\n");

            app = app->next;
        }
    }
    else{
        printf("Playlist vuota\n");
    }
}

//restituisce il puntatore alla canzone successiva rispetto a quella passata come puntatore se presente, altrimenti restituisce NULL
Song* nextSong(Song* s){
    if(s->next != NULL){
        return s->next;
    }
    else{
        return NULL;
    }
}

//restituisce il puntatore alla canzone precedente rispetto a quella passata come puntatore se presente, altrimenti restituisce NULL
Song* prevSong(Song* s){
    if(s->prev != NULL){
        return s->prev;
    }
    else{
        return NULL;
    }
}

//fonde le liste plA e plB in un’unica lista plC (anch’essa passata come parametro). NESSUN nuovo nodo deve essere allocato
void mergePlayList(PlayList* plA, PlayList* plB, PlayList* plC){
    plC->top = plA->top;
    Song *app = NULL;

    if(plB->top != NULL){
        app = plB->top;
        while(app != NULL){
            insertSong(plC, app);
            app = app->next;
        }
    }
}