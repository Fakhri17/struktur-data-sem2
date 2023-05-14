#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 25

typedef struct Stack{
  int top;
  char data[MAX_STACK_SIZE];
} Stack;

void init(Stack *stack){
  stack->top = -1;
}

bool isEmpty(Stack *stack){
  return stack->top == -1;
}

bool isFull(Stack *stack){
  return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, char value){
  if (isFull(stack)){
    printf("Stack is full!\n");
    return;
  }
  stack->data[++stack->top] = value;
}

char pop(Stack *stack){
  if (isEmpty(stack)){
    printf("Stack is empty!\n");
    return -1;
  }
  return stack->data[stack->top--];
}

void isPalindrome(char *str){
  Stack stack;
  init(&stack);
  for (int i = 0; i < strlen(str); i++){
    push(&stack, tolower(str[i]));
  }
  // printf("Output: ");
  for (int i = 0; i < strlen(str); i++){
    if (tolower(str[i]) != pop(&stack)){
      printf("Kata %s bukan kata palindrome\n", str);
      return;
    }
  }

  printf("Kata %s merupakan kata palindrome\n", str);
  
}

int main(){
  char str[MAX_STACK_SIZE];
  printf("Input: ");
  gets(str);
  isPalindrome(str);
  return 0;
}