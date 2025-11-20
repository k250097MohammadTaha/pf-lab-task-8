#include <stdio.h>

void analyzeData(int *arr, int n, int *max, int *min, float *avg) {
    int sum = 0;
    *max = arr[0];
    *min = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] > *max) *max = arr[i];
        if(arr[i] < *min) *min = arr[i];
        sum += arr[i];
    }
    *avg = (float)sum / n;
}

int main() {
    int arr[] = {50, 60, 40, 80, 75};
    int n = 5;
    int max, min;
    float avg;

    analyzeData(arr, n, &max, &min, &avg);

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    printf("Average = %.2f\n", avg);

    return 0;
}
