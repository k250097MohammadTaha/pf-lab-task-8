#include <stdio.h>

struct Team {
    char name[50];
    int rounds;
    int scores[50];
};

int totalScore(int scores[], int n) {
    if (n == 0) return 0;
    return scores[n-1] + totalScore(scores, n-1);
}

int main() {
    int numTeams;
    printf("Enter number of teams: ");
    scanf("%d", &numTeams);

    struct Team teams[numTeams];

    for (int i = 0; i < numTeams; i++) {
        printf("\nEnter name of team %d: ", i + 1);
        scanf("%s", teams[i].name);

        printf("Enter number of rounds for %s: ", teams[i].name);
        scanf("%d", &teams[i].rounds);

        for (int j = 0; j < teams[i].rounds; j++) {
            printf("Enter score for round %d: ", j + 1);
            scanf("%d", &teams[i].scores[j]);
        }
    }

    int threshold;
    printf("\nEnter score threshold to check: ");
    scanf("%d", &threshold);

    printf("\nTeam Scores and Status:\n");
    for (int i = 0; i < numTeams; i++) {
        int total = totalScore(teams[i].scores, teams[i].rounds);
        printf("Team: %s, Total Score: %d", teams[i].name, total);
        if (total >= threshold)
            printf(" -> Above Threshold\n");
        else
            printf(" -> Below Threshold\n");
    }

    return 0;
}
