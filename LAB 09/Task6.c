#include <stdio.h>
#include <string.h>

char* formatName(char *first, char *last) {
    static char full[100];
    full[0] = '\0';

    strcat(full, first);
    strcat(full, " ");
    strcat(full, last);

    return full;
}

int main() {
    char first[50], last[50];

    printf("Enter first name: ");
    scanf("%s", first);
    printf("Enter last name: ");
    scanf("%s", last);

    char *fullName = formatName(first, last);
    printf("Full Name: %s\n", fullName);

    return 0;
}
