#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int img[8][8], bright[8][8];
    int i, j;

    srand(time(0));
    printf("Original Matrix:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            img[i][j] = rand() % 256;
            printf("%3d ", img[i][j]);
        }
        printf("\n");
    }
    printf("\nBrightened Image Matrix:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            bright[i][j] = img[i][j] + 20;
            if (bright[i][j] > 255)
                bright[i][j] = 255;
            printf("%3d ", bright[i][j]);
        }
        printf("\n");
    }
    return 0;
}
