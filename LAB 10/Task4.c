#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TAGS 50
#define MAX_LEN 100

int countWords(char *str) {
    int cnt = 0;
    char temp[MAX_LEN];
    strcpy(temp, str);
    char *p = strtok(temp, " ");
    while(p) {
        cnt++;
        p = strtok(NULL, " ");
    }
    return cnt;
}

void loadTags(char tags[][MAX_LEN], int *n) {
    FILE *fp = fopen("tags.txt", "r");
    *n = 0;
    if(!fp) return;
    while(*n < MAX_TAGS && fgets(tags[*n], MAX_LEN, fp)) {
        tags[*n][strcspn(tags[*n], "\n")] = '\0';
        (*n)++;
    }
    fclose(fp);
}

void saveTags(char tags[][MAX_LEN], int n) {
    FILE *fp = fopen("tags.txt", "w");
    for(int i = 0; i < n; i++)
        fprintf(fp, "%s\n", tags[i]);
    fclose(fp);
}

void addTag(char tags[][MAX_LEN], int *n) {
    if(*n >= MAX_TAGS) {
        printf("Maximum tags reached.\n");
        return;
    }
    char temp[MAX_LEN];
    printf("Enter new tag (5–7 words): ");
    getchar();
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if(countWords(temp) > 7) {
        printf("Error: Tag exceeds 7 words.\n");
        return;
    }
    strcpy(tags[*n], temp);
    (*n)++;
}

void deleteTag(char tags[][MAX_LEN], int *n) {
    int idx;
    printf("Enter index of tag to delete: ");
    scanf("%d", &idx);
    if(idx < 0 || idx >= *n) {
        printf("Invalid index.\n");
        return;
    }
    for(int i = idx; i < *n - 1; i++)
        strcpy(tags[i], tags[i + 1]);
    (*n)--;
}

void updateTag(char tags[][MAX_LEN], int n) {
    int idx;
    printf("Enter index to update: ");
    scanf("%d", &idx);
    if(idx < 0 || idx >= n) {
        printf("Invalid index.\n");
        return;
    }
    char temp[MAX_LEN];
    printf("Enter updated tag (5–7 words): ");
    getchar();
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if(countWords(temp) > 7) {
        printf("Error: Tag exceeds 7 words.\n");
        return;
    }
    strcpy(tags[idx], temp);
}

void searchTag(char tags[][MAX_LEN], int n) {
    char key[MAX_LEN];
    printf("Enter phrase to search: ");
    getchar();
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';
    int found = 0;
    for(int i = 0; i < n; i++) {
        char *p = tags[i];
        if(strstr(p, key)) {
            printf("Found: %s (index %d)\n", p, i);
            found = 1;
        }
    }
    if(!found) printf("Not found.\n");
}

void displayTags(char tags[][MAX_LEN], int n) {
    for(int i = 0; i < n; i++)
        printf("%d: %s\n", i, tags[i]);
}

int main() {
    char tags[MAX_TAGS][MAX_LEN];
    int count = 0, choice;

    loadTags(tags, &count);

    while(1) {
        printf("\n1 Add\n2 Delete\n3 Update\n4 Search\n5 Display\n-1 Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == -1) break;
        else if(choice == 1) addTag(tags, &count);
        else if(choice == 2) deleteTag(tags, &count);
        else if(choice == 3) updateTag(tags, count);
        else if(choice == 4) searchTag(tags, count);
        else if(choice == 5) displayTags(tags, count);
        else printf("Invalid choice.\n");
    }

    saveTags(tags, count);
    return 0;
}
