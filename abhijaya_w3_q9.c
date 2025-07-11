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
    if (queue->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = item;
}
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front >= queue->rear) {
        queue->front = queue->rear = -1; 
    } else {
        queue->front++;
    }
    return item;
}
typedef struct Stack {
    Queue* queue1;
    Queue* queue2;
} Stack;
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->queue1 = createQueue();
    stack->queue2 = createQueue();
    return stack;
}
void push(Stack* stack, int item) {
    enqueue(stack->queue2, item);
    while (!isEmpty(stack->queue1)) {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }
    Queue* temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
}
int pop(Stack* stack) {
    return dequeue(stack->queue1);
}
int top(Stack* stack) {
    if (isEmpty(stack->queue1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->queue1->items[stack->queue1->front];
}
int isStackEmpty(Stack* stack) {
    return isEmpty(stack->queue1);
}
int main() {
    Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element is %d\n", top(stack)); 
    printf("Popped element is %d\n", pop(stack));
    printf("Top element is %d\n", top(stack)); 
    printf("Is stack empty? %d\n", isStackEmpty(stack)); 

    return 0;
}
