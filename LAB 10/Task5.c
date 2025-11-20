#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOTES 50
#define MAX_LEN 100

int countWords(char *str) {
    int cnt = 0;
    char *p = str;
    while(*p) {
        while(*p && *p == ' ') p++;
        if(*p) cnt++;
        while(*p && *p != ' ') p++;
    }
    return cnt;
}

void loadNotes(char notes[][MAX_LEN], int *n) {
    FILE *fp = fopen("episodes.txt", "r");
    *n = 0;
    if(!fp) return;
    while(*n < MAX_NOTES && fgets(notes[*n], MAX_LEN, fp)) {
        notes[*n][strcspn(notes[*n], "\n")] = '\0';
        (*n)++;
    }
    fclose(fp);
}

void saveNotes(char notes[][MAX_LEN], int n) {
    FILE *fp = fopen("episodes.txt", "w");
    for(int i = 0; i < n; i++)
        fprintf(fp, "%s\n", notes[i]);
    fclose(fp);
}

void addNote(char notes[][MAX_LEN], int *n) {
    if(*n >= MAX_NOTES) {
        printf("Maximum notes reached.\n");
        return;
    }
    char temp[MAX_LEN];
    printf("Enter new note title: ");
    getchar();
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    strcpy(notes[*n], temp);
    (*n)++;
}

void searchNote(char notes[][MAX_LEN], int n) {
    char key[MAX_LEN];
    printf("Enter search keyword: ");
    getchar();
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';
    int found = 0;
    for(int i = 0; i < n; i++) {
        char *p = notes[i];
        if(strstr(p, key)) {
            printf("Found: %s (index %d)\n", p, i);
            found = 1;
        }
    }
    if(!found) printf("Not found.\n");
}

void deleteNote(char notes[][MAX_LEN], int *n) {
    int idx;
    printf("Enter index to delete: ");
    scanf("%d", &idx);
    if(idx < 0 || idx >= *n) {
        printf("Invalid index.\n");
        return;
    }
    for(int i = idx; i < *n - 1; i++)
        strcpy(notes[i], notes[i + 1]);
    (*n)--;
}

void updateNote(char notes[][MAX_LEN], int n) {
    int idx;
    printf("Enter index to update: ");
    scanf("%d", &idx);
    if(idx < 0 || idx >= n) {
        printf("Invalid index.\n");
        return;
    }
    char temp[MAX_LEN];
    printf("Enter updated title: ");
    getchar();
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    strcpy(notes[idx], temp);
}

int countSpecificWord(char notes[][MAX_LEN], int n, char *word) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        char *p = notes[i];
        while(*p) {
            while(*p && *p == ' ') p++;
            char *start = p;
            while(*p && *p != ' ') p++;
            int len = p - start;
            if(len == (int)strlen(word) && strncmp(start, word, len) == 0)
                total++;
        }
    }
    return total;
}

void displayNotes(char notes[][MAX_LEN], int n) {
    for(int i = 0; i < n; i++)
        printf("%d: %s\n", i, notes[i]);
}

int main() {
    char notes[MAX_NOTES][MAX_LEN];
    int count = 0, choice;
    char word[MAX_LEN];

    loadNotes(notes, &count);

    while(1) {
        printf("\n1 Add\n2 Search\n3 Delete\n4 Update\n5 Count Word\n6 Display\n-1 Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == -1) break;
        else if(choice == 1) addNote(notes, &count);
        else if(choice == 2) searchNote(notes, count);
        else if(choice == 3) deleteNote(notes, &count);
        else if(choice == 4) updateNote(notes, count);
        else if(choice == 5) {
            printf("Enter word to count: ");
            getchar();
            fgets(word, MAX_LEN, stdin);
            word[strcspn(word, "\n")] = '\0';
            int c = countSpecificWord(notes, count, word);
            printf("Word '%s' appears %d times.\n", word, c);
        }
        else if(choice == 6) displayNotes(notes, count);
        else printf("Invalid choice.\n");
    }

    saveNotes(notes, count);
    return 0;
}
