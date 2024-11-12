#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Stalin Sort function
int stalinSort(int arr[], int n, int **sortedArr) {
    *sortedArr = (int *)malloc(n * sizeof(int)); // Allocate memory for sortedArr
    if (*sortedArr == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    int j = 0; // Index for the sorted array
    (*sortedArr)[j++] = arr[0]; // Keep the first element

    for (int i = 1; i < n; i++) {
        if (arr[i] >= (*sortedArr)[j - 1]) { // If the element is in non-decreasing order
            (*sortedArr)[j++] = arr[i];      // Add it to the sorted array
        }
    }
    return j; // Return the number of elements in the sorted array
}

int main() {
    int arr[] = {3, 5, 2, 8, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *sortedArr = NULL; // Pointer for the sorted results

    printf("Original array:\n");
    printArray(arr, n);

    int sortedSize = stalinSort(arr, n, &sortedArr);

    printf("Stalin sorted array:\n");
    printArray(sortedArr, sortedSize);

    // Free dynamically allocated memory
    free(sortedArr);

    return 0;
}
