#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct Node {
    char* option;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue *queue) {
    if(queue->front == NULL){
        return true;
    }
    return false ;
}

void printQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        printf("%s\n", current->option);
        current = current->next;
    }
}
// Function to add an element to the rear of the queue
void enqueue(Queue *queue, char * option) {
    Node *newNode = (Node*) malloc(sizeof(Node));   
    newNode->option = strdup(option);  // ⬅️ allocate and copy the string

    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return; // Empty queue, nothing to dequeue
    }

    Node *temp = queue->front;

    queue->front = queue->front->next;

  
    if (queue->front == NULL) {
        queue->rear = NULL; // Queue becomes empty after dequeue
    }
    free(temp);

}

// Function to retrieve the front element of the queue without removing it
char* front(Queue* q) {
    if (!isEmpty(q)) {
        return q->front->option;
    }
    return NULL;
}


// Function to free the memory allocated for the queue
void destroyQueue(Queue *queue) {
    Node *current = queue->front;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;

        free(temp->option);  // free the strdup'd string
        free(temp);
    }
    free(queue);
}


#endif /* QUEUE_H */
