// CIRCULAR QUEUE

#include <stdio.h>
#include <stdlib.h>

// node in circular queue
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// enqueue
void enqueue(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
    } else {
        rear->next = newNode;
    }

    rear = newNode;
    rear->next = front; // to make it circular
}

// dequeue 
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = front->data;
    struct Node* temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // to make it circular
    }

    free(temp);
    return item;
}

// display
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    printf("ketaki mahajan / A-3 / 16014022050\n");
    int A[] = {11, 33, 55, 10, 66};
    int n = sizeof(A) / sizeof(A[0]);

    printf("\nEnqueueing elements into the circular queue:\n");
    for (int i = 0; i < n; i++) {
        enqueue(A[i]);
    }

    printf("Queue contents: ");
    display();

    printf("\nDequeuing elements from the circular queue:\n");
    while (front != NULL) {
        int item = dequeue();
        printf("Dequeued: %d\n", item);
    }

    printf("\nQueue contents: ");
    display();

    return 0;
}
