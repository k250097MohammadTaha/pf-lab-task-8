#include <stdio.h>
#include <string.h>

void reverseWord(char str[], int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseWord(str, start + 1, end - 1);
}

int isPalindrome(char str[], int start, int end) {
    if (start >= end) return 1;
    if (str[start] != str[end]) return 0;
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char word[50];

    for (int i = 0; i < n; i++) {
        printf("\nEnter word %d: ", i + 1);
        scanf("%s", word);

        char reversed[50];
        strcpy(reversed, word);
        reverseWord(reversed, 0, strlen(reversed) - 1);

        printf("Original Word: %s\n", word);
        printf("Reversed Word: %s\n", reversed);

        if (isPalindrome(word, 0, strlen(word) - 1))
            printf("It is a palindrome.\n");
        else
            printf("It is not a palindrome.\n");
    }

    return 0;
}
