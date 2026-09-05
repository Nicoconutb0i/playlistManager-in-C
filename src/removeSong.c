#include "playlist.h"
#define MAX_DUPLICATES 10

void removeSongByTitle(PLAYLIST *list);
void removeSongByID(PLAYLIST *list);
void removeSongByPos(PLAYLIST *list);

void removeSong(PLAYLIST *list){
    if(list->head == NULL || list == NULL){
        printf("The playlist is empty. No songs to remove.\n");
        return;
    }

    int option;
    printf("How would you like to remove the song?\n");
    printf("1. Remove by Title\n");
    printf("2. Remove by ID");
    printf("3. Remove by position in playlist\n");
    scanf("%d", &option);

    switch(option){
        case 1:
            removeSongByTitle(list);
            break;
        
        case 2:
            removeSongByID(list);
            break;

        case 3:
            removeSongByPos(list);
            break;

        default:
            printf("Invalid option. Please try again.\n");
    }
}

void removeSongByTitle(PLAYLIST *list){
    char title[50];
    printf("Enter the title of the song you want to remove: ");
    fgets(title, sizeof(title) ,stdin);
    title[strcspn(title, "\n")] = '\0';

    int matchCount = 0;
    SONG *matches[MAX_DUPLICATES];
    SONG *temp = list->head;
    
    printf("Searching for \"%s\"...\n", title);
    while(temp != NULL){
        if(strcmp(temp->title, title) == 0){
            if(matchCount < MAX_DUPLICATES){
                matches[matchCount] = temp;
                matchCount++;
                printf("[%d] %s - %s | ID: %d |\n", matchCount, temp->title, temp->artist, temp->songID);
            } else {
                printf("(Standard limit reached. Some duplicates may not be listed.)\n");
                break;
            }
        }
        temp = temp->next;
    }
    
    if(matchCount == 0){
        printf("There are no songs in the playlist titled %s", title);
        return;
    }

    int choice = 1;
    if(matchCount > 1){
        printf("Enter the number of the song you would like to remove: ");
        if(scanf("%d", &choice) != 1 || choice < 1 || choice > matchCount){
            printf("Invalid choice. Cancelled\n");
            while(getchar() != '\n');
            return;
        }
        while(getchar() != '\n');
    }

    SONG *toDelete = matches[choice - 1];

    if(toDelete->prev == NULL){
        list->head = toDelete->next;
    } else {
        toDelete->prev->next = toDelete->next;
    }

    if(toDelete->next != NULL){
        toDelete->next->prev = toDelete->prev;
    } else {
        list->tail = toDelete->prev;
    }

    free(toDelete);
    printf("Song successfully removed.\n");
}

void removeSongByID(PLAYLIST *list){

}

void removeSongByPos(PLAYLIST *list){
    
}