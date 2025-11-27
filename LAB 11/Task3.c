#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    int daysPresent;
};

int totalAttendance(struct Employee emp[], int n) {
    if (n == 0)
        return 0;
    return emp[n-1].daysPresent + totalAttendance(emp, n-1);
}

void lowAttendance(struct Employee emp[], int n, int minDays) {
    printf("\nEmployees with less than %d days attendance:\n", minDays);
    for (int i = 0; i < n; i++) {
        if (emp[i].daysPresent < minDays) {
            printf("Name: %s, ID: %d, Days Present: %d\n", emp[i].name, emp[i].id, emp[i].daysPresent);
        }
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Days Present: ");
        scanf("%d", &emp[i].daysPresent);
    }

    int minDays;
    printf("\nEnter minimum required days: ");
    scanf("%d", &minDays);

    int total = totalAttendance(emp, n);
    printf("\nTotal attendance of all employees: %d\n", total);

    lowAttendance(emp, n, minDays);

    return 0;
}
