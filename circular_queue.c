#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Insert element into queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Remove element from queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    return 0;
}
