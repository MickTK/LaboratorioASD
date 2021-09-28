//
// Created by Michele Melis on 21/04/2020.
//

#ifndef E6_FUNCTIONS_H
#define E6_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_TITLE 50
#define DIM_GENRE 50
#define DIM_NAME 50

//struttura che rappresenta una CANZONE
struct song
{
    char title[DIM_TITLE];
    char genre[DIM_GENRE];
    float length;
    struct song* prev;
    struct song* next;
};

typedef struct song Song;

//struttura che rappresenta una PLAYLIST
struct playlist
{
    char name[DIM_NAME];
    Song* top;
};

typedef struct playlist PlayList;

//funzioni (gia' definite) per l'acquisizione e per la stampa di una canzone
Song* acquireSong(); //acquisisce i dati di UNA canzone chiedendoli all'utente
void printSong(Song* s); //stampa i dati relativi ad UNA canzone (passata tramite puntatore)

//prototipi funzioni STUDENTE
void insertSong(PlayList* pl, Song* s);
Song* findSong(PlayList* pl, char title[]);
void modifySong(PlayList* pl, Song* s);
void deleteSong(PlayList* pl, Song* s);
void printPlayList(PlayList* pl);
Song* nextSong(Song* s);
Song* prevSong(Song* s);
void mergePlayList(PlayList* plA, PlayList* plB, PlayList* plC);

#endif //E6_FUNCTIONS_H