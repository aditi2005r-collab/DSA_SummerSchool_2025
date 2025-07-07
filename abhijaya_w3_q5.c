#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
void push(Stack* stack, char item) {
    stack->items[++stack->top] = item;
}
char pop(Stack* stack) {
    return stack->items[stack->top--];
}
char peek(Stack* stack) {
    return stack->items[stack->top];
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack();
    int j = 0;

    for (int i = 0; infix[i]; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token; 
        } else if (token == '(') {
            push(stack, token);
        } else if (token == ')') {
            while (stack->top != -1 && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); 
        } else {
            while (stack->top != -1 && precedence(peek(stack)) >= precedence(token)) {
                postfix[j++] = pop(stack);
            }
            push(stack, token);
        }
    }

    while (stack->top != -1) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0'; 
    free(stack);
}
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; 

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
