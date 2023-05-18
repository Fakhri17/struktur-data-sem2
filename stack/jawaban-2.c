#include <stdio.h>
#include <string.h>
#include <ctype.h>

// deklarasi maksimal ukuran stack
#define MAX_STACK_SIZE 25

// deklarasi tipe data stack
typedef struct Stack{
  int top;
  char data[MAX_STACK_SIZE];
} Stack;

// init untuk menginisialisasi stack
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

// deklarasi fungsi push untuk menambahkan data ke dalam stack
void push(Stack *stack, char value){
  // jika stack penuh, maka tidak bisa menambahkan data
  if (isFull(stack)){
    printf("Stack is full!\n");
    return;
  }
  // jika tidak penuh, maka data ditambahkan ke dalam stack dengan menambahkan +1 dari top
  stack->data[++stack->top] = value;
}

// deklarasi fungsi pop untuk mengeluarkan data dari stack
char pop(Stack *stack){
  // jika stack kosong, maka tidak bisa mengeluarkan data
  if (isEmpty(stack)){
    printf("Stack is empty!\n");
    return -1;
  }
  // jika tidak kosong, maka data dikeluarkan dari stack dengan mengurangi -1 dari top
  return stack->data[stack->top--];
}

// deklarasi fungsi isPalindrome untuk mengecek apakah kata palindrome
void isPalindrome(char *str){
  // deklarasi variabel stack
  Stack stack;
  // inisialisasi stack
  init(&stack);
  // push setiap karakter dari string ke dalam stack dengan melakukan perulangan
  // serta mengubah karakter menjadi lowercase agar tidak terjadi perbedaan antara huruf besar dan kecil
  for (int i = 0; i < strlen(str); i++){
    push(&stack, tolower(str[i]));
  }
  
  // lakukan perulangan untuk membandingkan setiap karakter dari string dengan karakter yang diambil dari stack
  for (int i = 0; i < strlen(str); i++){
    // jika karakter tidak sama, maka kata bukan kata palindrome
    if (tolower(str[i]) != pop(&stack)){
      printf("Kata %s bukan kata palindrome\n", str);
      return;
    }
  }
  // jika semua karakter sama, maka kata merupakan kata palindrome
  printf("Kata %s merupakan kata palindrome\n", str);
  
}

int main(){
  // deklarasi variabel str untuk menyimpan string
  char str[MAX_STACK_SIZE];
  // input string
  printf("Input: ");
  gets(str);
  // panggil fungsi isPalindrome
  isPalindrome(str);
  return 0;
}