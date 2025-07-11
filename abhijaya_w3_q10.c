#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
int isEmpty(Queue* queue) {
    return queue->front == -1;
}
void enqueue(Queue* queue, int item) {
    if (queue->rear == MAX - 1) return; 
    if (isEmpty(queue)) queue->front = 0;
    queue->items[++queue->rear] = item;
}
int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1; 
    int item = queue->items[queue->front];
    if (queue->front >= queue->rear) queue->front = queue->rear = -1; 
    else queue->front++;
    return item;
}
void reverseFirstKElements(Queue* queue, int k) {
    if (isEmpty(queue) || k <= 0 || k > (queue->rear - queue->front + 1)) return;

    int stack[MAX], top = -1;
    for (int i = 0; i < k; i++) {
        stack[++top] = dequeue(queue);
    }
    while (top != -1) {
        enqueue(queue, stack[top--]);
    }
    for (int i = 0; i < (queue->rear - queue->front + 1) - k; i++) {
        enqueue(queue, dequeue(queue));
    }
}
void displayQueue(Queue* queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}
int main() {
    Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("Original queue: ");
    displayQueue(queue);
    int k = 3; 
    reverseFirstKElements(queue, k);
    printf("Queue after reversing the first %d elements: ", k);
    displayQueue(queue);
    free(queue); 
    return 0;
}
