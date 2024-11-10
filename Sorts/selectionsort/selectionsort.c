#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE *file;
    char *filename = "numbers.txt";
    int *arr = NULL;
    int n = 0, temp;

    // open the file to count numbers
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // count the numbers in the file
    while (fscanf(file, "%d", &temp) == 1) {
        n++;
    }
    fclose(file);

    // allocate memory dynamically for the number of elements
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // read the numbers into the dynamically allocated array
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        free(arr);  // free allocated memory in case of error
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    printf("Unsorted array: \n");
    printArray(arr, n);

    // start clock
    clock_t start, end;
    start = clock();

    // Sort the array
    selectionSort(arr, n);

    // Stop clock
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    printArray(arr, n);

    // print sorting time
    printf("Selection Sort took %f seconds to sort %d elements.\n", time_taken, n);

    // free dynamically allocated memory
    free(arr);

    return 0;
}
