#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10

typedef struct Kata{
  char kata[MAX_STACK_SIZE];
  int top;
}Kata;

void push(Kata *kata, char value){
  if (kata->top == MAX_STACK_SIZE - 1){
    printf("Stack is full!\n");
    return;
  }
  kata->top++;
  kata->kata[kata->top] = value;
}

char pop(Kata *kata){
  if (kata->top == -1){
    printf("Stack is empty!\n");
    return -1;
  }
  char value = kata->kata[kata->top];
  kata->top--;
  return value;
}

int main(){
  Kata kata;
  kata.top = -1;
  char value[10] = "hallo";
  for (int i = 0; i < strlen(value); i++){
    push(&kata, value[i]);
  }

  printf("awal: ");
  for (int i = 0; i < strlen(value); i++){
    printf("%c", value[i]);
  }

  printf("\nHasil: ");
  for (int i = 0; i < strlen(value); i++){
    printf("%c", pop(&kata));
  }
  
  printf("\n");
  return 0;
}