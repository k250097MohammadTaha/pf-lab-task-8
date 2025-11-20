#include <stdio.h>
#include <string.h>

#define MAX_AFF 50
#define MAX_LEN 150

int countWords(char *s) {
    int cnt = 0;
    char temp[200];
    strcpy(temp, s);
    char *t = strtok(temp, " ");
    while(t) {
        cnt++;
        t = strtok(NULL, " ");
    }
    return cnt;
}

void loadAffirmations(char arr[][MAX_LEN], int *n) {
    FILE *fp = fopen("affirm.txt", "r");
    *n = 0;
    if(!fp) return;

    while(*n < MAX_AFF && fgets(arr[*n], MAX_LEN, fp)) {
        arr[*n][strcspn(arr[*n], "\n")] = '\0';
        (*n)++;
    }
    fclose(fp);
}

void saveAffirmations(char arr[][MAX_LEN], int n) {
    FILE *fp = fopen("affirm.txt", "w");
    for(int i = 0; i < n; i++)
        fprintf(fp, "%s\n", arr[i]);
    fclose(fp);
}

void addAffirmation(char arr[][MAX_LEN], int *n) {
    if(*n >= MAX_AFF) {
        printf("Maximum affirmations reached.\n");
        return;
    }

    char temp[MAX_LEN];
    printf("Enter new affirmation (max 7 words): ");
    getchar();
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    if(countWords(temp) > 7) {
        printf("Error: Affirmation exceeds 7 words.\n");
        return;
    }

    strcpy(arr[*n], temp);
    (*n)++;
}

void deleteAffirmation(char arr[][MAX_LEN], int *n) {
    int idx;
    printf("Enter index to delete: ");
    scanf("%d", &idx);

    if(idx < 0 || idx >= *n) {
        printf("Invalid index.\n");
        return;
    }

    for(int i = idx; i < *n - 1; i++)
        strcpy(arr[i], arr[i + 1]);

    (*n)--;
}

void updateAffirmation(char arr[][MAX_LEN], int n) {
    int idx;
    printf("Enter index to update: ");
    scanf("%d", &idx);

    if(idx < 0 || idx >= n) {
        printf("Invalid index.\n");
        return;
    }

    char temp[MAX_LEN];
    printf("Enter updated affirmation (max 7 words): ");
    getchar();
    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    if(countWords(temp) > 7) {
        printf("Error: Affirmation exceeds 7 words.\n");
        return;
    }

    strcpy(arr[idx], temp);
}

void searchAffirmation(char arr[][MAX_LEN], int n) {
    char phrase[MAX_LEN];
    printf("Enter phrase to search: ");
    getchar();
    fgets(phrase, MAX_LEN, stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    int found = 0;
    for(int i = 0; i < n; i++) {
        if(strstr(arr[i], phrase)) {
            printf("Found: %s (index %d)\n", arr[i], i);
            found = 1;
        }
    }
    if(!found) printf("Not found.\n");
}

int main() {
    char affirmations[MAX_AFF][MAX_LEN];
    int count = 0, choice;

    loadAffirmations(affirmations, &count);

    while(1) {
        printf("\n1 Add\n2 Delete\n3 Update\n4 Search\n-1 Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == -1) break;
        else if(choice == 1) addAffirmation(affirmations, &count);
        else if(choice == 2) deleteAffirmation(affirmations, &count);
        else if(choice == 3) updateAffirmation(affirmations, count);
        else if(choice == 4) searchAffirmation(affirmations, count);
        else printf("Invalid choice.\n");
    }

    saveAffirmations(affirmations, count);

    return 0;
}
