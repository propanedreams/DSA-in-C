#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a linked list node
struct Node {
    char name[50];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void appendNode(struct Node** head, const char* name) {
    struct Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s --> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Append characters from Supernatural to the list
    appendNode(&head, "Sam Winchester");
    appendNode(&head, "Dean Winchester");
    appendNode(&head, "Castiel");
    appendNode(&head, "Crowley");
    appendNode(&head, "Bobby Singer");
    appendNode(&head, "Charlie Bradbury");

    // Display the list
    printf("Characters from Supernatural:\n");
    displayList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}
