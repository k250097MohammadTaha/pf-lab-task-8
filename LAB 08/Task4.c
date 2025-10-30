#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    int hall[row][col];
    srand(time(0));

    int totalEmpty = 0, maxEmpty = 0, rowMax = 0;

    printf("\nSeating Arrangement (1 = Occupied, 0 = Empty):\n");
    for (int i = 0; i < row; i++) {
        int rowEmpty = 0;
        for (int j = 0; j < col; j++) {
            hall[i][j] = rand() % 2;
            printf("%d ", hall[i][j]);
            if (hall[i][j] == 0) rowEmpty++;
        }
        totalEmpty += rowEmpty;
        if (rowEmpty > maxEmpty) {
            maxEmpty = rowEmpty;
            rowMax = i + 1;
        }
        printf("\n");
    }

    printf("\nTotal Available Seats: %d\n", totalEmpty);
    printf("Row with Most Empty Seats: Row %d (%d empty seats)\n", rowMax, maxEmpty);

    return 0;
}
