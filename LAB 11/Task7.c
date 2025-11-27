#include <stdio.h>
#include <string.h>

struct Forecast {
    char luckyColor[20];
    int luckyNumber;
    char advice[100];
};

struct User {
    char name[50];
    int day;
    int month;
    char zodiac[20];
    struct Forecast dailyForecast;
};

void assignZodiac(struct User *user) {
    int d = user->day, m = user->month;

    if ((m == 3 && d >= 21) || (m == 4 && d <= 19))
        strcpy(user->zodiac, "Aries");
    else if ((m == 4 && d >= 20) || (m == 5 && d <= 20))
        strcpy(user->zodiac, "Taurus");
    else if ((m == 5 && d >= 21) || (m == 6 && d <= 20))
        strcpy(user->zodiac, "Gemini");
    else if ((m == 6 && d >= 21) || (m == 7 && d <= 22))
        strcpy(user->zodiac, "Cancer");
    else if ((m == 7 && d >= 23) || (m == 8 && d <= 22))
        strcpy(user->zodiac, "Leo");
    else if ((m == 8 && d >= 23) || (m == 9 && d <= 22))
        strcpy(user->zodiac, "Virgo");
    else if ((m == 9 && d >= 23) || (m == 10 && d <= 22))
        strcpy(user->zodiac, "Libra");
    else if ((m == 10 && d >= 23) || (m == 11 && d <= 21))
        strcpy(user->zodiac, "Scorpio");
    else if ((m == 11 && d >= 22) || (m == 12 && d <= 21))
        strcpy(user->zodiac, "Sagittarius");
    else if ((m == 12 && d >= 22) || (m == 1 && d <= 19))
        strcpy(user->zodiac, "Capricorn");
    else if ((m == 1 && d >= 20) || (m == 2 && d <= 18))
        strcpy(user->zodiac, "Aquarius");
    else
        strcpy(user->zodiac, "Pisces");
}

void inputUserData(struct User *user) {
    printf("Enter name: ");
    scanf(" %[^\n]", user->name);
    printf("Enter birth day: ");
    scanf("%d", &user->day);
    printf("Enter birth month: ");
    scanf("%d", &user->month);
    assignZodiac(user);
}

void displayHoroscope(struct User *user) {
    printf("\nHoroscope for %s:\n", user->name);
    printf("Zodiac Sign: %s\n", user->zodiac);
    printf("Lucky Color: %s\n", user->dailyForecast.luckyColor);
    printf("Lucky Number: %d\n", user->dailyForecast.luckyNumber);
    printf("Advice: %s\n", user->dailyForecast.advice);
}

void updateForecast(struct Forecast *forecast) {
    printf("Enter lucky color: ");
    scanf(" %[^\n]", forecast->luckyColor);
    printf("Enter lucky number: ");
    scanf("%d", &forecast->luckyNumber);
    printf("Enter advice: ");
    scanf(" %[^\n]", forecast->advice);
}

int main() {
    int n;
    printf("Enter number of users: ");
    scanf("%d", &n);

    struct User users[n];

    for (int i = 0; i < n; i++) {
        printf("\nInput data for user %d:\n", i + 1);
        inputUserData(&users[i]);
    }

    int choice;
    do {
        printf("\n1. Display Horoscope\n2. Update Forecast for a User\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int idx;
            printf("Enter user number (1-%d): ", n);
            scanf("%d", &idx);
            displayHoroscope(&users[idx - 1]);
        } else if (choice == 2) {
            int idx;
            printf("Enter user number to update forecast (1-%d): ", n);
            scanf("%d", &idx);
            updateForecast(&users[idx - 1].dailyForecast);
        }

    } while (choice != 3);

    return 0;
}
