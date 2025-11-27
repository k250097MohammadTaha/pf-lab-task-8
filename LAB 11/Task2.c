#include <stdio.h>

void countdown(int days) {
    if (days < 0) return;
    printf("Days left: %d\n", days);
    if (days == 0) {
        printf("Event is today!\n");
        return;
    }
    countdown(days - 1);
}

int main() {
    int n;
    printf("Enter number of events: ");
    scanf("%d", &n);

    int daysLeft[n];

    for (int i = 0; i < n; i++) {
        printf("Enter days left for event %d: ", i + 1);
        scanf("%d", &daysLeft[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("\nCountdown for event %d:\n", i + 1);
        countdown(daysLeft[i]);
    }

    return 0;
}
