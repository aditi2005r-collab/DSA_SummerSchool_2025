#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 

typedef struct Stack {
    char items[MAX];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1; 
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, char item) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    }
}
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0'; 
}
void reverseString(char* str) {
    int length = strlen(str);
    Stack* stack = createStack();
    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < length; i++) {
        str[i] = pop(stack);
    }

    free(stack);
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
