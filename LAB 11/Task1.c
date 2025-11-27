#include <stdio.h>

struct Gift {
    char name[50];
    char type[50];
    float price;
    int quantity;
};

void displayGift(struct Gift g) {
    printf("Name: %s\n", g.name);
    printf("Type: %s\n", g.type);
    printf("Price: %.2f\n", g.price);
    printf("Quantity: %d\n", g.quantity);
    printf("-------------------------\n");
}

void giftsAbovePrice(struct Gift gifts[], int n, float limit) {
    printf("\nGifts Above Price %.2f:\n", limit);
    for (int i = 0; i < n; i++) {
        if (gifts[i].price > limit) {
            displayGift(gifts[i]);
        }
    }
}

void giftsAboveQuantity(struct Gift gifts[], int n, int limit) {
    printf("\nGifts With Quantity More Than %d:\n", limit);
    for (int i = 0; i < n; i++) {
        if (gifts[i].quantity > limit) {
            displayGift(gifts[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter number of gifts: ");
    scanf("%d", &n);

    struct Gift gifts[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Gift %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", gifts[i].name);
        printf("Type: ");
        scanf("%s", gifts[i].type);
        printf("Price: ");
        scanf("%f", &gifts[i].price);
        printf("Quantity: ");
        scanf("%d", &gifts[i].quantity);
    }

    float priceLimit;
    int quantityLimit;

    printf("\nEnter price limit to filter expensive gifts: ");
    scanf("%f", &priceLimit);

    printf("Enter quantity limit to filter high-stock gifts: ");
    scanf("%d", &quantityLimit);

    giftsAbovePrice(gifts, n, priceLimit);
    giftsAboveQuantity(gifts, n, quantityLimit);

    return 0;
}
