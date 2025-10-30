#include <stdio.h>

int main() {
    char word[3][10];
    int i, j, count = 0;
    printf("Enter 3 words:\n");
    for (i = 0; i < 3; i++) {
        scanf("%s", word[i]);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; word[i][j] != '\0'; j++) {
            char ch = word[i][j];
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }
    }
    printf("Total number of vowels: %d\n", count);
    return 0;
}
