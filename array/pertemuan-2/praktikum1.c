#include <stdio.h>
#include <stdlib.h>

// int *funcPointer(){
//   int num = 10;
//   return &num;
// }


int main(){

  int x = 100;
  int *ptr = &x; // --> variabel ptr

  *ptr = 200; // --> isi dari variabel ptr
  x = 10;
  printf("x = %d\n", x);
  printf("alamat memori x = %x\n", &x);
  printf("alamat memori ptr = %x\n", ptr);
  printf("ptr = %d\n",*ptr);

  printf("\nVoid Pointer\n");
  void *ptr2 = &x;
  printf("alamat memori ptr2 = %x\n", ptr2);
  printf("ptr2 = %d\n", *(int*)ptr2);
  
  // Null Pointer
  printf("\nNull Pointer\n");
 
  int* ptr3 = NULL;
  // *ptr3 = 100;
  
  // derefencing only if the pointer have any value
  if (ptr3 == NULL) {
    printf("Pointer does not point to anything\n");
  }
  else {
    printf("Value pointed by pointer: %d\n", *ptr3);
  }

  // Dangling Pointer
  printf("\nDangling Pointer\n");
  int *ptr4 = (int*)malloc(sizeof(int));
  *ptr4 = 100;
  printf("ptr4 = %d\n", *ptr4);
  free(ptr4);
  

  // int *ptr4 = NULL;
  // ptr4 = funcPointer();
  // printf("%d",*ptr4);

  // Array Pointer
    printf("\nArray Pointer\n");
    int angka[5] = {1,2,3,4,5};
    printf("alamat array %x\n", angka);
    // *nama_variabel = &nama_array[0];
    printf("*angka   = %d\n", *angka);
    printf("angka[0] = %d\n", angka[0]);

    printf("*angka   = %d\n", *(angka + 3));
    printf("angka[3] = %d\n", angka[3]);
  
  return 0;
}