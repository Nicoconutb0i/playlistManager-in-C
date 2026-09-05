#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song{
    char title[50];
    char artist[50];
    int songID; // this should be a string
    
    struct song *next;
    struct song *prev;
}SONG;

typedef struct{
    SONG *head;
    SONG *tail;
    int count;
}PLAYLIST;

void menu();

void addSong(PLAYLIST *);
void removeSong(PLAYLIST *);
void searchSong(PLAYLIST *);
void searchArtist();
void displayPlaylist(PLAYLIST *);

#endif
