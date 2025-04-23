#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000000 

void insertionSort(long long arr[], int n) {
    for (int i = 1; i < n; i++) {
        long long key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter the number of phone numbers: ");
    scanf("%d", &n);

    long long phoneNumbers[n];
    srand(time(0));

    printf("Generated Phone Numbers:\n");
    for (int i = 0; i < n; i++) {
        phoneNumbers[i] = MAX + rand() % 1000000000;
        printf("%lld\n", phoneNumbers[i]);
    }

    clock_t start, end;
    start = clock();
    insertionSort(phoneNumbers, n);
    end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Phone Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld\n", phoneNumbers[i]);
    }

    printf("Time taken: %lf seconds\n", timeTaken);

    return 0;
}
