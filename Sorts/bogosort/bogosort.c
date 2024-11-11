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

// Shuffling function using Fisher-Yates algorithm 
void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int randomIndex = rand() % (i + 1);
        // Swap arr[i] and arr[randomIndex]
        int temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}

// Bogo Sort function
int bogoSort(int arr[], int n) {
    int shuffle_count = 0;
    // Keep shuffling until the array is sorted
    while (!isSorted(arr, n)) {
        shuffle(arr, n);
        shuffle_count++; // Increment the count for each shuffle
    }
    return shuffle_count; // Return the total number of shuffles
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {3, 5, 1, 4, 2, 7, 6, 9, 8, 10};
    int n = 10;

    // Seed random number generator
    srand(time(0));

    printf("Unsorted array:\n");
    printArray(arr, n);

    // Start timing
    clock_t start = clock();

    // Perform Bogo Sort and get the shuffle count
    int shuffle_count = bogoSort(arr, n);

    // Stop timing
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    printArray(arr, n);
    printf("Bogo Sort took %f seconds and %d shuffles to sort the array.\n", time_taken, shuffle_count);

    return 0;
}
