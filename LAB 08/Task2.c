#include <stdio.h>
int main() {
    char name[5][20];
    int i;
    printf("Enter names of 5 students:\n");
    for (i = 0; i < 5; i++) {
        scanf("%s", name[i]);
    }
    printf("\nNames of students:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", name[i]);
    }

    return 0;
}
