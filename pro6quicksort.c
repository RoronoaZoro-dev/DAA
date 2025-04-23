#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to partition the array
int partition(int a[], int low, int high) {
    int i, j, temp, pivot;
    pivot = a[low]; // Selecting the first element as the pivot
    i = low + 1;
    j = high;

    while (1) {
        while (i < high && a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}

// Function to perform Quick Sort
void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quick_sort(a, low, j - 1);
        quick_sort(a, j + 1, high);
    }
}

// Main function
int main() {
    int i, n, a[200000];
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of student records: ");
    scanf("%d", &n);

    // Generating random roll numbers
    printf("The roll numbers are: \n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100; // Random numbers between 0 and 99
        printf("%d ", a[i]);
    }

    // Measure sorting time
    starttime = clock();
    quick_sort(a, 0, n - 1);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    // Display sorted roll numbers
    printf("\nSorted roll numbers are: \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
