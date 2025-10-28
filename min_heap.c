#include <stdio.h>

int heap[50];
int n = 0;

void insert(int val) {
    int i = ++n;
    heap[i] = val;

    // Heapify up
    while (i > 1 && heap[i / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i = i / 2;
    }
}

int deleteMin() {
    int min = heap[1];
    heap[1] = heap[n--];
    int i = 1, j = 2;

    // Heapify down
    while (j <= n) {
        if (j < n && heap[j] > heap[j + 1])
            j++;
        if (heap[i] > heap[j]) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
            j = 2 * i;
        } else
            break;
    }
    return min;
}

void display() {
    for (int i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(40);
    insert(20);
    insert(30);
    insert(10);
    insert(50);

    printf("Min Heap: ");
    display();

    printf("Deleted Min: %d\n", deleteMin());

    printf("Heap after deletion: ");
    display();

    return 0;
}
