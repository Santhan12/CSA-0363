#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    
    stack->top++;
    stack->arr[stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    
    int value = stack->arr[stack->top];
    stack->top--;
    return value;
}

// Peek at the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printf("Top element: %d\n", peek(&stack));
    
    printf("Popped %d from the stack.\n", pop(&stack));
    printf("Popped %d from the stack.\n", pop(&stack));
    
    printf("Top element: %d\n", peek(&stack));
    
    push(&stack, 40);
    
    printf("Top element: %d\n", peek(&stack));
    
    return 0;
}

