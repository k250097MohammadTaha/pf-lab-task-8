#include <stdio.h>

float calculateBonus(float salary) {
    if(salary < 30000)
        return salary * 0.20;
    else
        return salary * 0.10;
}

int main() {
    float salary[5], bonus[5], totalPayout = 0;

    for(int i = 0; i < 5; i++) {
        printf("Enter salary of employee %d: ", i + 1);
        scanf("%f", &salary[i]);
        bonus[i] = calculateBonus(salary[i]);
    }

    for(int i = 0; i < 5; i++) {
        printf("Employee %d Bonus: %.2f\n", i + 1, bonus[i]);
        totalPayout += salary[i] + bonus[i];
    }

    printf("Total Payout: %.2f\n", totalPayout);

    return 0;
}
