#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to shuffle the array
void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int randomIndex = rand() % n;
        // Swap arr[i] and arr[randomIndex]
        int temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}

// Bogo Sort function
void bogoSort(int arr[], int n) {
    // Keep shuffling until the array is sorted
    while (!isSorted(arr, n)) {
        shuffle(arr, n);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {3, 5, 1, 4, 2,7,6,9,8,10};
    int n = 10;

    // Seed random number generator
    srand(time(0));

    printf("Unsorted array:\n");
    printArray(arr, n);

    bogoSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
