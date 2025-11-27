#include <stdio.h>
#include <string.h>

struct Item {
    char name[50];
    char category[50];
    int quantity;
};

void filterByCategory(struct Item *items, int n, char category[]) {
    printf("\nItems in category '%s':\n", category);
    for (int i = 0; i < n; i++) {
        if (strcmp((items + i)->category, category) == 0) {
            printf("Name: %s, Quantity: %d\n", (items + i)->name, (items + i)->quantity);
        }
    }
}

void filterByQuantity(struct Item *items, int n, int minQty) {
    printf("\nItems with quantity >= %d:\n", minQty);
    for (int i = 0; i < n; i++) {
        if ((items + i)->quantity >= minQty) {
            printf("Name: %s, Category: %s, Quantity: %d\n", (items + i)->name, (items + i)->category, (items + i)->quantity);
        }
    }
}

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item inventory[n];
    struct Item *ptr = inventory;

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for item %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", (ptr + i)->name);
        printf("Category: ");
        scanf("%s", (ptr + i)->category);
        printf("Quantity: ");
        scanf("%d", &(ptr + i)->quantity);
    }

    char category[50];
    int minQty;

    printf("\nEnter category to filter: ");
    scanf("%s", category);

    printf("Enter minimum quantity to filter: ");
    scanf("%d", &minQty);

    filterByCategory(ptr, n, category);
    filterByQuantity(ptr, n, minQty);

    return 0;
}
