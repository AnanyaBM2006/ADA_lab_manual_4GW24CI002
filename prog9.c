#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minindex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        if (minindex != i) {
            int tmp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = tmp;
        }
    }
}

void generaterandomnumbers(int arr[], int n) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10000;
    }
}

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    /* accept any positive number of elements; selection sort is O(n^2)
       so very large n will be slow. Require n > 0. */
    if (n <= 0) {
        printf("Please enter a positive value for number of elements\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("malloc");
        return 1;
    }

    generaterandomnumbers(arr, n);

    clock_t start = clock();
    selectionsort(arr, n);
    clock_t end = clock();

    double timetaken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("time taken to sort %d elements: %f seconds\n", n, timetaken);

    /* print sorted elements */
    printf("Sorted elements:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    if (n % 10 != 0)
        printf("\n");

    free(arr);
    return 0;
}