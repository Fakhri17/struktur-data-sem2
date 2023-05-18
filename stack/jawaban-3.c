#include <stdio.h>
#include <string.h>
#include <ctype.h>
// deklarasi maksimal stack
#define MAX_STACK_SIZE 20

// deklarasi struct stack
typedef struct Stack{
  int top;
  char data[MAX_STACK_SIZE];
} Stack;

// deklarasi inisialisasi stack
void init(Stack *stack){
  stack->top = -1;
}

// deklarasi fungsi isEmpty untuk mengecek apakah stack kosong
int isEmpty(Stack *stack){
  return stack->top == -1;
}

// deklarasi fungsi isFull untuk mengecek apakah stack penuh
int isFull(Stack *stack){
  return stack->top == MAX_STACK_SIZE - 1;
}

// deklarasi fungsi push untuk menambahkan data ke stack
void push(Stack *stack, char value){
  // jika stack penuh tidak bisa menambahkan data
  if (isFull(stack)){
    printf("Stack is full!\n");
    return;
  }
  // jika tidak penuh, tambahkan data ke stack
  stack->data[++stack->top] = value;
}

// deklarasi fungsi pop untuk mengeluarkan data dari stack
char pop(Stack *stack){
  // jika stack kosong tidak bisa mengeluarkan data
  if (isEmpty(stack)){
    printf("Stack is empty!\n");
    return -1;
  }
  // jika tidak kosong, keluarkan data dari stack
  return stack->data[stack->top--];
}

// deklarasi precedence untuk mengecek tingkat prioritas operator
int precedence(char c){
  if (c == '^') return 3;
  if (c == '*' || c == '/') return 2;
  if (c == '+' || c == '-') return 1;
  return -1;
}

// deklarasi fungsi infixToPostfix untuk mengubah infix menjadi postfix
void infixToPostfix(char *str){
  Stack stack;
  init(&stack);
  char postfix[MAX_STACK_SIZE];
  // deklarasi variabel opt untuk menampung data postfix
  int opt = 0;
  // lakukan perulangan untuk setiap karakter pada infix
  for (int i = 0; i < strlen(str); i++){
    // jika karakter adalah operand, tambahkan ke postfix
    if (isalnum(str[i])){
      postfix[opt++] = str[i];
    } 
    // jika karakter adalah kurung buka, tambahkan ke stack
    else if (str[i] == '('){
      push(&stack, str[i]);
    }
    // jika karakter adalah kurung tutup, keluarkan data dari stack hingga menemukan kurung buka 
    else if (str[i] == ')'){
      while (!isEmpty(&stack) && stack.data[stack.top] != '('){
        postfix[opt++] = pop(&stack);
      }
      pop(&stack);
    } 
    // jika karakter adalah operator, keluarkan data dari stack hingga menemukan operator dengan prioritas lebih rendah
    else {
      while (!isEmpty(&stack) && precedence(str[i]) <= precedence(stack.data[stack.top])){
        postfix[opt++] = pop(&stack);
      }
      push(&stack, str[i]);
    }
  }
  // keluarkan data dari stack hingga stack kosong
  while (!isEmpty(&stack)){
    postfix[opt++] = pop(&stack);
  }
  // tambahkan null terminator pada postfix fungsinya untuk menandakan akhir dari string
  postfix[opt] = '\0';
  // tampikan postfix
  printf("Postfix: %s\n", postfix);
}

int main(){
  // deklarasi variabel str untuk menampung infix
  char str[MAX_STACK_SIZE];
  // minta input infix
  printf("Masukkan infix: ");
  gets(str);
  // panggil fungsi infixToPostfix untuk mengubah infix menjadi postfix
  infixToPostfix(str);
}