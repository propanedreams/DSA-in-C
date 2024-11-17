#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a Node structure
typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

// Define a Stack structure
typedef struct Stack {
    Node* top;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

// Function to create a new node
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Push: Add an element to the top of the stack
void push(Stack* stack, const char* name) {
    Node* newNode = createNode(name);
    if (!newNode) return;

    newNode->next = stack->top;
    stack->top = newNode;

    printf("%s has been pushed onto the stack.\n", name);
}

// Pop: Remove the top element from the stack
void pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("The stack is empty. Nothing to pop.\n");
        return;
    }

    Node* temp = stack->top;
    printf("%s has been popped from the stack.\n", temp->name);
    stack->top = stack->top->next;
    free(temp);
}

// Peek: View the top element of the stack without removing it
void peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("The stack is empty.\n");
    } else {
        printf("Top of the stack: %s\n", stack->top->name);
    }
}

// Display all elements in the stack
void displayStack(Stack* stack) {
    if (stack->top == NULL) {
        printf("The stack is empty.\n");
        return;
    }

    Node* temp = stack->top;
    printf("Stack contents:\n");
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

// Free the memory used by the stack
void freeStack(Stack* stack) {
    Node* temp = stack->top;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(stack);
}

int main() {
    // Create a stack
    Stack* stack = createStack();

    // Push characters onto the stack
    push(stack, "Dean Winchester");
    push(stack, "Sam Winchester");
    push(stack, "Castiel");
    push(stack, "Crowley");

    // Display the stack
    printf("\nCurrent stack:\n");
    displayStack(stack);

    // Peek at the top element
    printf("\nPeeking at the stack:\n");
    peek(stack);

    // Pop elements from the stack
    printf("\nPopping elements:\n");
    pop(stack);
    pop(stack);

    // Display the stack after popping
    printf("\nStack after popping:\n");
    displayStack(stack);

    // Add more characters
    printf("\nAdding more characters to the stack:\n");
    push(stack, "Bobby Singer");
    push(stack, "Charlie Bradbury");
    push(stack, "Jack Kline");

    // Display the updated stack
    printf("\nUpdated stack:\n");
    displayStack(stack);

    // Empty the stack completely
    printf("\nEmptying the stack:\n");
    while (stack->top != NULL) {
        pop(stack);
    }

    // Try to pop from an empty stack
    printf("\nTrying to pop from an empty stack:\n");
    pop(stack);

    // Free the stack
    freeStack(stack);

    return 0;
}
