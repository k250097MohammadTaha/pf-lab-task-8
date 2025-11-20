#include <stdio.h>
#include <string.h>

#define MAX_SONGS 10
#define MAX_LEN 100

void loadPlaylist(char list[][MAX_LEN], int *total) {
    FILE *fp = fopen("playlist.txt", "r");
    *total = 0;

    if(fp == NULL) return;

    while(*total < MAX_SONGS && fgets(list[*total], MAX_LEN, fp)) {
        list[*total][strcspn(list[*total], "\n")] = '\0';
        (*total)++;
    }

    fclose(fp);
}

void savePlaylist(char list[][MAX_LEN], int total) {
    FILE *fp = fopen("playlist.txt", "w");
    for(int i = 0; i < total; i++)
        fprintf(fp, "%s\n", list[i]);
    fclose(fp);
}

void addSong(char list[][MAX_LEN], int *total) {
    if(*total >= MAX_SONGS) {
        printf("Playlist full.\n");
        return;
    }

    printf("Enter song title: ");
    getchar();
    fgets(list[*total], MAX_LEN, stdin);
    list[*total][strcspn(list[*total], "\n")] = '\0';
    (*total)++;
}

void deleteSong(char list[][MAX_LEN], int *total) {
    char title[MAX_LEN];
    printf("Enter title to delete: ");
    getchar();
    fgets(title, MAX_LEN, stdin);
    title[strcspn(title, "\n")] = '\0';

    for(int i = 0; i < *total; i++) {
        if(strcmp(list[i], title) == 0) {
            for(int j = i; j < *total - 1; j++)
                strcpy(list[j], list[j + 1]);
            (*total)--;
            printf("Deleted.\n");
            return;
        }
    }
    printf("Not found.\n");
}

void updateSong(char list[][MAX_LEN], int total) {
    char oldTitle[MAX_LEN], newTitle[MAX_LEN];

    printf("Enter old title: ");
    getchar();
    fgets(oldTitle, MAX_LEN, stdin);
    oldTitle[strcspn(oldTitle, "\n")] = '\0';

    for(int i = 0; i < total; i++) {
        if(strcmp(list[i], oldTitle) == 0) {
            printf("Enter new title: ");
            fgets(newTitle, MAX_LEN, stdin);
            newTitle[strcspn(newTitle, "\n")] = '\0';
            strcpy(list[i], newTitle);
            printf("Updated.\n");
            return;
        }
    }
    printf("Not found.\n");
}

void searchSong(char list[][MAX_LEN], int total) {
    char keyword[MAX_LEN];

    printf("Enter title to search: ");
    getchar();
    fgets(keyword, MAX_LEN, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    for(int i = 0; i < total; i++) {
        if(strcmp(list[i], keyword) == 0) {
            printf("Found at position %d\n", i + 1);
            return;
        }
    }
    printf("Not found.\n");
}

void sortPlaylist(char list[][MAX_LEN], int total) {
    char temp[MAX_LEN];

    for(int i = 0; i < total; i++) {
        for(int j = i + 1; j < total; j++) {
            if(strcmp(list[i], list[j]) > 0) {
                strcpy(temp, list[i]);
                strcpy(list[i], list[j]);
                strcpy(list[j], temp);
            }
        }
    }
}

int main() {
    char playlist[MAX_SONGS][MAX_LEN];
    int songCount = 0;
    int choice;

    loadPlaylist(playlist, &songCount);

    while(1) {
        printf("\n1. Add Song\n2. Delete Song\n3. Update Song\n4. Search Song\n-1 to Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == -1) break;

        if(choice == 1) addSong(playlist, &songCount);
        else if(choice == 2) deleteSong(playlist, &songCount);
        else if(choice == 3) updateSong(playlist, songCount);
        else if(choice == 4) searchSong(playlist, songCount);
        else printf("Invalid.\n");
    }

    sortPlaylist(playlist, songCount);
    savePlaylist(playlist, songCount);

    printf("\nFinal Playlist:\n");
    for(int i = 0; i < songCount; i++)
        printf("%s\n", playlist[i]);

    return 0;
}
