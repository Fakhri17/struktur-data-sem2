// create program infix to postfix

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 20

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

int precedence(char c){
  if (c == '^') return 3;
  if (c == '*' || c == '/') return 2;
  if (c == '+' || c == '-') return 1;
  return -1;

}

void infixToPostfix(char *str){
  Stack stack;
  init(&stack);
  char postfix[MAX_STACK_SIZE];
  int opt = 0;
  for (int i = 0; i < strlen(str); i++){
    if (isalnum(str[i])){
      postfix[opt++] = str[i];
    } 
    else if (str[i] == '('){
      push(&stack, str[i]);
    } 
    else if (str[i] == ')'){
      while (!isEmpty(&stack) && stack.data[stack.top] != '('){
        postfix[opt++] = pop(&stack);
      }
      pop(&stack);
    } 
    else {
      while (!isEmpty(&stack) && precedence(str[i]) <= precedence(stack.data[stack.top])){
        postfix[opt++] = pop(&stack);
      }
      push(&stack, str[i]);
    }
  }
  while (!isEmpty(&stack)){
    postfix[opt++] = pop(&stack);
  }
  postfix[opt] = '\0';
  printf("Postfix: %s\n", postfix);
}

int main(){
  char str[MAX_STACK_SIZE];
  printf("Masukkan infix: ");
  gets(str);
  infixToPostfix(str);
}