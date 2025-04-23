#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n, a[1000], key, bottom, top, mid, j, temp;
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of Products5: ");
    scanf("%d", &n);

    srand(time(0)); // Seed for random numbers
    printf("The Product IDs are:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d\t", a[i]);
    }

    // Bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Product ID List:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    printf("\nEnter the Product ID to be searched: ");
    scanf("%d", &key);

    starttime = clock();

    bottom = 0;
    top = n - 1;
    int found = 0;

    while (bottom <= top) {
        mid = (bottom + top) / 2;

        if (key == a[mid]) {
            found = 1;
            break;
        } else if (key < a[mid]) {
            top = mid - 1;
        } else {
            bottom = mid + 1;
        }
    }

    if (found) {
        printf("Product found!!\n");
        printf("Product %d found at position: %d\n", key, mid + 1);
    } else {
        printf("Search failed\n%d not found\n", key);
    }

    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", clk);

    return 0;
}
