#include <stdio.h>

int main() {
    int n;
    printf("Enter size of square board (N): ");
    scanf("%d", &n);
    int board[n][n], rotate[n][n];
    printf("Enter elements of the board:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    printf("\nOriginal Game Board:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotate[j][n - 1 - i] = board[i][j];
        }
    }
    printf("\nRotated Game Board (90° Clockwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", rotate[i][j]);
        }
        printf("\n");
    }

    return 0;
}
