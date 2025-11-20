#include <stdio.h>
#include <string.h>

#define MAX_RECIPES 40
#define NAME_LEN 120

void loadRecipes(char rec[][NAME_LEN], int *n) {
    FILE *fp = fopen("recipes.txt", "r");
    *n = 0;

    if(!fp) return;

    while(*n < MAX_RECIPES && fgets(rec[*n], NAME_LEN, fp)) {
        rec[*n][strcspn(rec[*n], "\n")] = '\0';
        (*n)++;
    }
    fclose(fp);
}

void saveRecipes(char rec[][NAME_LEN], int n) {
    FILE *fp = fopen("recipes.txt", "w");
    for(int i = 0; i < n; i++)
        fprintf(fp, "%s\n", rec[i]);
    fclose(fp);
}

void addRecipe(char rec[][NAME_LEN], int *n) {
    if(*n >= MAX_RECIPES) {
        printf("Max limit reached.\n");
        return;
    }

    char temp[NAME_LEN];
    printf("Enter recipe name: ");
    getchar();
    fgets(temp, NAME_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    strcpy(rec[*n], temp);
    (*n)++;
}

void updateRecipe(char rec[][NAME_LEN], int n) {
    int index;
    printf("Enter recipe index to update: ");
    scanf("%d", &index);

    if(index < 0 || index >= n) {
        printf("Invalid index.\n");
        return;
    }

    char temp[NAME_LEN];
    printf("Enter updated name: ");
    getchar();
    fgets(temp, NAME_LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    strcpy(rec[index], temp);
}

void deleteRecipe(char rec[][NAME_LEN], int *n) {
    int index;
    printf("Enter recipe index to delete: ");
    scanf("%d", &index);

    if(index < 0 || index >= *n) {
        printf("Invalid index.\n");
        return;
    }

    for(int i = index; i < *n - 1; i++)
        strcpy(rec[i], rec[i + 1]);

    (*n)--;
}

void searchRecipe(char rec[][NAME_LEN], int n) {
    char target[NAME_LEN];
    printf("Search for: ");
    getchar();
    fgets(target, NAME_LEN, stdin);
    target[strcspn(target, "\n")] = '\0';

    for(int i = 0; i < n; i++) {
        if(strstr(rec[i], target))
            printf("Match: %s (index %d)\n", rec[i], i);
    }
}

void sortRecipes(char rec[][NAME_LEN], int n) {
    char temp[NAME_LEN];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(strcmp(rec[i], rec[j]) > 0) {
                strcpy(temp, rec[i]);
                strcpy(rec[i], rec[j]);
                strcpy(rec[j], temp);
            }
}

int main() {
    char recipes[MAX_RECIPES][NAME_LEN];
    int count = 0, choice;

    loadRecipes(recipes, &count);

    while(1) {
        printf("\n1 Add\n2 Update\n3 Delete\n4 Search\n-1 Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == -1) break;
        else if(choice == 1) addRecipe(recipes, &count);
        else if(choice == 2) updateRecipe(recipes, count);
        else if(choice == 3) deleteRecipe(recipes, &count);
        else if(choice == 4) searchRecipe(recipes, count);
    }

    sortRecipes(recipes, count);
    saveRecipes(recipes, count);

    return 0;
}
