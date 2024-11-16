#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a Node structure
typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

// Define a Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    queue->front = queue->rear = NULL;
    return queue;
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

// Enqueue: Add a character to the queue
void enqueue(Queue* queue, const char* name) {
    Node* newNode = createNode(name);
    if (!newNode) return;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%s has been added to the queue.\n", name);
}

// Dequeue: Remove a character from the front of the queue
void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("The queue is empty. Nothing to dequeue.\n");
        return;
    }

    Node* temp = queue->front;
    printf("%s has been removed from the queue.\n", temp->name);
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
}

// Peek at the front element of the queue
void peekFront(Queue* queue) {
    if (queue->front == NULL) {
        printf("The queue is empty.\n");
    } else {
        printf("Front of the queue: %s\n", queue->front->name);
    }
}

// Peek at the rear element of the queue
void peekRear(Queue* queue) {
    if (queue->rear == NULL) {
        printf("The queue is empty.\n");
    } else {
        printf("Rear of the queue: %s\n", queue->rear->name);
    }
}

// Display all elements in the queue
void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    Node* temp = queue->front;
    printf("Queue contents: ");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free the memory used by the queue
void freeQueue(Queue* queue) {
    Node* temp = queue->front;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(queue);
}

int main() {
    // Create a queue
    Queue* queue = createQueue();

    // Enqueue characters
    enqueue(queue, "Dean Winchester");
    enqueue(queue, "Sam Winchester");
    enqueue(queue, "Castiel");
    enqueue(queue, "Crowley");

    // Display the queue
    printf("\nCurrent queue:\n");
    displayQueue(queue);

    // Peek at the front and rear
    printf("\nPeeking at the queue:\n");
    peekFront(queue);
    peekRear(queue);

    // Dequeue some characters
    printf("\nDequeuing characters:\n");
    dequeue(queue);
    dequeue(queue);

    // Display the queue after dequeue
    printf("\nQueue after dequeuing:\n");
    displayQueue(queue);

    // Free the queue
    freeQueue(queue);

    return 0;
}
