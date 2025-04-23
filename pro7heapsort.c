#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void heapbottomup(int h[], int n) {
    int i, heap, v, j, k;
    for (i = n / 2; i > 0; i--) {
        k = i;
        v = h[k];
        heap = FALSE;
        while (!heap && (2 * k) <= n) {
            j = 2 * k;
            if (j < n)
                if (h[j] < h[j + 1])
                    j = j + 1;
            if (v >= h[j])
                heap = TRUE;
            else {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}

void heapsort(int h[], int n) {
    int temp, last = n;
    if (n <= 1)
        return;
    else {
        heapbottomup(h, n);
        temp = h[last];
        h[last] = h[1];
        h[1] = temp;
        last--;
        heapsort(h, n - 1);
    }
}

int main() {
    int h[20], n, i;
    double clk;
    clock_t starttime, endtime;

    printf("\nEnter the number of resumes\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        h[i] = rand() % 100;
        printf("The candidate's rank is: \t%d\n", h[i]);
    }

    starttime = clock();
    heapsort(h, n);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nThe ranks in sorted order:\n");
    for (i = 1; i <= n; i++)
        printf("\t%d", h[i]);

    printf("\nThe run time is %f seconds\n", clk);
    return 0;
}
