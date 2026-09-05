#include "playlist.h"

void displayPlaylist(PLAYLIST *list){
    int i = 1;
    
    if(list->head == NULL){
        printf("The playlist is empty. No songs to display.\n");
        return;
    }
   
    SONG *temp = list->head;
    printf("Playlist:\n");

    while(temp != NULL){
        printf("[%d] %s - %s | ID: %d |\n", i, temp->title, temp->artist, temp->songID);
        i++;
        temp = temp->next;
    }
}