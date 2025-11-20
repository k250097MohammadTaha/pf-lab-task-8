#include <stdio.h>

void inputData(int arr[], int n) {
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void findTwoRoads(int arr[], int n, int target, int *i1, int *i2) {
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(arr[i] + arr[j] == target) {
                *i1 = i;
                *i2 = j;
                return;
            }
}

int main() {
    int n, target, r1, r2;
    printf("Enter number of roads: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter vehicle counts: ");
    inputData(arr, n);

    printf("Enter target: ");
    scanf("%d", &target);

    findTwoRoads(arr, n, target, &r1, &r2);

    printf("Roads: %d and %d\n", r1, r2);

    return 0;
}
