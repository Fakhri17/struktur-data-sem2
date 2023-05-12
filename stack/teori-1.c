#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef struct Stack{
  int top;
  int data[MAX_STACK_SIZE];
} Stack;

void init(Stack *stack){
  stack->top = -1;
}

int isEmpty(Stack *stack){
  return stack->top == -1;
}

int isFull(Stack *stack){
  return stack->top == MAX_STACK_SIZE - 1;
}

int peek(Stack *stack){
  return isEmpty(stack) ? -1 : stack->data[stack->top];
}

void push(Stack *stack, int value){
  if (isFull(stack)){
    printf("Stack is full!\n");
    return;
  }
  stack->top++;
  stack->data[stack->top] = value;
}

int pop(Stack *stack){
  int value = stack->data[stack->top];
  stack->top--;
  return (isEmpty(stack)) ? -1 : value;
}

void printStack(Stack *stack){
  if (isEmpty(stack)){
    printf("Stack is empty!\n");
    return;
  }
  printf("\nStack: ");
  for (int i = stack->top; i >= 0; i--){
    printf("%d ", stack->data[i]);
  }
  printf("\n");
}

int main(){
  Stack stack;
  init(&stack);
  int choice, value;
  while (1)
  {
    printStack(&stack);
    printf("\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
      case 1:
        printf("Input value: ");
        scanf("%d", &value);
        push(&stack, value);
        break;
      case 2:
        value = pop(&stack);
        if (value != -1){
          printf("Poped value: %d\n", value);
        }
        break;
      case 3:
        value = peek(&stack);
        if (value != -1){
          printf("Peeked value: %d\n", value);
        }
        break;
      case 4:
        printf("Exiting...\n");     
        return 0;
      default:
        printf("Invalid choice!\n");
    }
  }
}

