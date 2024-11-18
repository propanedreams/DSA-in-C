#include <stdio.h>
#include <string.h>

// Function to perform linear search on an array of strings
int linearSearch(char arr[][50], int size, const char* target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            return i;  // Target found, return index
        }
    }
    return -1;  // Target not found
}

int main() {
    // List of Supernatural characters (unsorted)
    char characters[][50] = {
        "Dean Winchester",
        "Sam Winchester",
        "Castiel",
        "Crowley",
        "Bobby Singer",
        "Charlie Bradbury",
        "Jack Kline",
        "John Winchester"
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

    // Perform linear search
    int result = linearSearch(characters, size, target);

    // Print the result
    if (result != -1) {
        printf("\n'%s' found at position %d in the list.\n", target, result + 1);
    } else {
        printf("\n'%s' not found in the list.\n", target);
    }

    return 0;
}
