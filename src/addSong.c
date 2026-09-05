#include "playlist.h"

void insertAtBeginning(PLAYLIST *, SONG *);
void insertAtEnd(PLAYLIST *, SONG *);
void insertAtPosition(PLAYLIST *, SONG *);

SONG *createNode(int ID, const char *title, char *artist){
    SONG *newSong = malloc(sizeof(SONG));

    newSong->next = NULL;
    newSong->prev = NULL;
    newSong->songID = ID;

    strncpy(newSong->title, title, 50);
    newSong->title[49] = '\0';

    strncpy(newSong->artist, artist, 50);
    newSong->title[49] = '\0';

    return newSong;
}

void addSong(PLAYLIST *list){
    int ID;
    char title[50];
    char artist[50];

    printf("Enter the song title: ");
    fgets(title, sizeof(title), stdin);

    printf("Enter the artist of the song: ");
    fgets(artist, sizeof(artist), stdin);

    printf("Enter the song ID: ");
    fgets(ID, sizeof(ID), stdin);

    SONG *newSong = createNode(ID, title, artist);

    printf("Where would you like to insert the song?\n");
    printf("1. At the beginning of the playlist\n");
    printf("2. At the end of the playlist\n");
    printf("3. At a specific position in the playlist\n");
    
    int option = getchar();
    while(getchar() != '\n');

    switch(option){
        case '1':
            insertAtBeginning(list, newSong);
            break;

        case '2':
            insertAtEnd(list, newSong);
            break;

        case '3':
            insertAtPosition(list, newSong);
            break;

        default:
            printf("Invalid option. Please try again!\n");
            return;
    }
}

void insertAtBeginning(PLAYLIST *list, SONG *newSong){
    if(list->head == NULL){
        list->head = newSong;
        list->tail = newSong;
    } else {
        newSong->next = list->head;
        list->head->prev = newSong;
        list->head = newSong;
    }
    list->count++;
}

void insertAtEnd(PLAYLIST *list, SONG *newSong){
    if(list->tail == NULL){
        list->head = newSong;
        list->tail = newSong;
    } else {
        newSong->prev = list->tail;
        list->tail->next = newSong;
        list->tail = newSong;
    }
    list->count++;
}

void insertAtPosition(PLAYLIST *list, SONG *newSong){
    int position;
        printf("Enter the position to insert the song: ");
        scanf("%d", &position);
    
    if(position < 1 || position > list->count + 1){
        printf("Invalid position. Please try again!\n");
        return;
    }

    if(position == 1){
        insertAtBeginning(list, newSong);
    } else if(position == list->count + 1){
        insertAtEnd(list, newSong);
    } else {
        SONG *temp = list->head;

        for(int i = 1; i < position - 1; i++){
            temp = temp->next;
        }

        newSong->next = temp->next;
        newSong->prev = temp;
        temp->next->prev = newSong;
        temp->next = newSong;

        list->count++;
    }
}