#include "playlist.h"

int main(){
    int option = 'X';

    PLAYLIST *list = malloc(sizeof(PLAYLIST));
    list->head = NULL;
    list->tail = NULL;

    while(option != '6'){
        menu();
        option = getchar();
        while(getchar() != '\n');

        switch(option){
            case '1':
                printf("You have chosen to add a song to the playlist!\n");
                addSong(list);
                break;

            case '2':
                printf("You have chosen to remove a song from the playlist!\n");
                removeSong(list);
                break;

            case '3':
                printf("You have chosen to search for a song in the playlist!\n");
                break;

            case '4':
                printf("You have chosen to search for an artist in the playlist!\n");
                break;
            
            case '5':
                printf("You have chosen to display the playlist!\n");
                displayPlaylist(list);
                break;

            case '6':
                printf("Thank you for using the playlist manager. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again!\n");
        }
    }
    free(list);
    return 0;
}
