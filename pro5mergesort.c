#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[500000]; // Large array to store employee IDs

void merge(int low, int mid, int high);
void merge_sort(int low, int high);

void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int b[500000]; // Temporary array for merging

    // Merge two halves
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        b[k++] = a[i++];
    }

    // Copy remaining elements from right half
    while (j <= high) {
        b[k++] = a[j++];
    }

    // Copy back sorted elements to original array
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

int main() {
    int n, i;
    double clk;
    clock_t starttime, endtime;

    printf("MERGE SORT\n");
    printf("Enter the number of employee records: ");
    scanf("%d", &n);

    srand(time(0)); // Seed for random number generation
    printf("The Employee IDs are:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100; // Generate random employee IDs
        printf("%d ", a[i]);
    }

    starttime = clock(); // Start time measurement
    merge_sort(0, n - 1); // Corrected function call
    endtime = clock(); // End time measurement

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nEmployee IDs in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
