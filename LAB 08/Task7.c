#include <stdio.h>

int main() {
    int inventory[2][3][4];
    int sectionTotal[2] = {0};
    int shelfSum, maxShelf = 0, maxQuantity = 0;
    printf("Enter quantities for 2 sections, 3 shelves, and 4 items:\n");
    for (int s = 0; s < 2; s++) {
        for (int sh = 0; sh < 3; sh++) {
            for (int it = 0; it < 4; it++) {
                scanf("%d", &inventory[s][sh][it]);
                sectionTotal[s] += inventory[s][sh][it];
            }
        }
    }
    printf("\nTotal items in each section:\n");
    for (int s = 0; s < 2; s++) {
        printf("Section %d: %d\n", s + 1, sectionTotal[s]);
    }
    for (int s = 0; s < 2; s++) {
        for (int sh = 0; sh < 3; sh++) {
            shelfSum = 0;
            for (int it = 0; it < 4; it++) {
                shelfSum += inventory[s][sh][it];
            }
            if (shelfSum > maxQuantity) {
                maxQuantity = shelfSum;
                maxShelf = sh + 1;
            }
        }
    }
    printf("\nShelf with highest total quantity: Shelf %d (%d items)\n", maxShelf, maxQuantity);
    return 0;
}
