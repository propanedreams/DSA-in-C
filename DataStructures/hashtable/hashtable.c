#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Number of buckets in the hash table

// Define the structure for a hash table node
typedef struct Node {
    char key[50];
    char value[50];
    struct Node* next;
} Node;

// Define the hash table structure
typedef struct HashTable {
    Node* buckets[TABLE_SIZE];
} HashTable;

// Hash function to compute the index for a key
unsigned int hash(const char* key) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = (hashValue * 31) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

// Initialize the hash table
HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (!table) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

// Add a key-value pair to the hash table
void addElement(HashTable* table, const char* key, const char* value) {
    unsigned int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

// Retrieve a value by its key
char* getElement(HashTable* table, const char* key) {
    unsigned int index = hash(key);
    Node* current = table->buckets[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;  // Key not found
}

// Remove an element by its key
void removeElement(HashTable* table, const char* key) {
    unsigned int index = hash(key);
    Node* current = table->buckets[index];
    Node* prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }
            free(current);
            printf("Element with key '%s' removed.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key '%s' not found.\n", key);
}

// Print the hash table
void printHashTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* current = table->buckets[i];
        while (current) {
            printf("(%s: %s) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Free the hash table
void freeHashTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table->buckets[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table);
}

int main() {
    // Create a hash table
    HashTable* table = createHashTable();

    // Add elements
    addElement(table, "Dean", "Winchester");
    addElement(table, "Sam", "Winchester");
    addElement(table, "Castiel", "Angel");
    addElement(table, "Crowley", "Demon");
    

    // Print the hash table
    printf("Hash Table:\n");
    printHashTable(table);

    // Retrieve elements
    printf("\nRetrieving elements:\n");
    printf("Dean: %s\n", getElement(table, "Dean"));
    printf("Castiel: %s\n", getElement(table, "Castiel"));

    // Remove an element
    printf("\nRemoving 'Crowley':\n");
    removeElement(table, "Crowley");

    // Print the hash table after removal
    printf("\nHash Table after removal:\n");
    printHashTable(table);

    // Free the hash table
    freeHashTable(table);

    return 0;
}
