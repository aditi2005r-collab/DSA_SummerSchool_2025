
#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100 
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}
void push(Stack* stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}
int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return 0; 
}
int calculate(char* s) {
    Stack stack;
    initStack(&stack);
    
    int result = 0;
    int num = 0;
    int sign = 1; 
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0'); 
        } 
        else if (s[i] == '+') {
            result += sign * num; 
            num = 0; 
            sign = 1; 
        } 
        else if (s[i] == '-') {
            result += sign * num; 
            num = 0; 
            sign = -1; 
        } 
        else if (s[i] == '(') {
            push(&stack, result); 
            push(&stack, sign);
            result = 0; 
            sign = 1; 
        } 
        else if (s[i] == ')') {
            result += sign * num; 
            num = 0; 
            result *= pop(&stack); 
            result += pop(&stack); 
        }
    }
    result += sign * num;

    return result;
}

int main() {          
    printf("%d\n", calculate("(1+(4+5+2)-3)+(6+8)"));  
    
    return 0;
}
