#include <stdio.h>

void inputData(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter patients for day %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

float averagePatients(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

int busiestDay(int arr[], int n) {
    int maxIndex = 0;
    for(int i = 1; i < n; i++)
        if(arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

int slowestDay(int arr[], int n) {
    int minIndex = 0;
    for(int i = 1; i < n; i++)
        if(arr[i] < arr[minIndex])
            minIndex = i;
    return minIndex;
}

int main() {
    int patients[7];
    
    inputData(patients, 7);

    float avg = averagePatients(patients, 7);
    int maxDay = busiestDay(patients, 7);
    int minDay = slowestDay(patients, 7);

    printf("\nAverage Patients per Day: %.2f\n", avg);
    printf("Busiest Day: Day %d (%d patients)\n", maxDay + 1, patients[maxDay]);
    printf("Slowest Day: Day %d (%d patients)\n", minDay + 1, patients[minDay]);

    return 0;
}
