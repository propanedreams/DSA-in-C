#include <stdio.h>
#include <string.h>

// Function to perform binary search on a sorted array of strings
int binarySearch(char arr[][50], int size, const char* target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Compare the middle element with the target
        int comparison = strcmp(arr[mid], target);
        if (comparison == 0) {
            return mid;  // Target found
        } else if (comparison < 0) {
            low = mid + 1;  // Target is in the upper half
        } else {
            high = mid - 1;  // Target is in the lower half
        }
    }

    return -1;  // Target not found
}

int main() {
    // Sorted list of Supernatural characters
    char characters[][50] = {
        "Bobby Singer",
        "Castiel",
        "Charlie Bradbury",
        "Crowley",
        "Dean Winchester",
        "Jack Kline",
        "John Winchester",
        "Sam Winchester"
    };

    int size = sizeof(characters) / sizeof(characters[0]);

    // Print the list of characters
    printf("Supernatural characters:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, characters[i]);
    }

    // Prompt the user to search for a character
    char target[50];
    printf("\nEnter the character name to search: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';  // Remove the newline character

    // Perform binary search
    int result = binarySearch(characters, size, target);

    // Print the result
    if (result != -1) {
        printf("\n'%s' found at position %d in the sorted list.\n", target, result + 1);
    } else {
        printf("\n'%s' not found in the list.\n", target);
    }

    return 0;
}
