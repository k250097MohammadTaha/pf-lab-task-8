#include <stdio.h>

int main() {
    int marks[5][4];
    float avg[5];
    int highest[4];
    int i, j;
    printf("Enter marks of 5 students in 4 subjects:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &marks[i][j]);
        }
    }
    for (i = 0; i < 5; i++) {
        int sum = 0;
        for (j = 0; j < 4; j++) {
            sum += marks[i][j];
        }
        avg[i] = sum / 4.0;
    }
    for (j = 0; j < 4; j++) {
        highest[j] = marks[0][j];
        for (i = 1; i < 5; i++) {
            if (marks[i][j] > highest[j])
                highest[j] = marks[i][j];
        }
    }
    printf("\nAverage marks of each student: [");
    for (i = 0; i < 5; i++) {
        printf("%.2f", avg[i]);
        if (i < 4) printf(", ");
    }
    printf("]\n");

    printf("Highest marks in each subject: [");
    for (j = 0; j < 4; j++) {
        printf("%d", highest[j]);
        if (j < 3) printf(", ");
    }
    printf("]\n");

    return 0;
}
