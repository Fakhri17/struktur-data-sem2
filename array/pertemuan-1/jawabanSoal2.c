#include <stdio.h>

// fungsi untuk mengurutkan array dengan menggunakan buble sort
// dengan arr dan len sebagai parameter
void bubleSort(int *arr, int len){
  // loop untuk mengurutkan array
  for (int i = 0; i < len - 1; i++)
  {
    // variabel tmp sebagai variabel sementara
    int tmp;
    // loop untuk mengurutkan array
    for (int j = 0; j < len - 1 - i; j++)
    {
      // ascending menggunakan arr > arr + 1
      // descending menggunakan arr < arr + 1
      if (arr[j] > arr[j+1])
      {
        // proses pertukaran nilai jika index ke j lebih besar dari index ke j + 1
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }  
    }
  }
}

// fungsi untuk menampilkan array
void printArr(int *arr, int len){
  for (int i = 0; i < len; i++)
  {
    printf("%d, ", arr[i]);
  }
}

int main(){
  
  // Inisialisasi array dengan nilai yang sudah ditentukan
  // dimana x sebagai sebuah variabel array bertipe data integer
  int x[5] = {15, 21, 4, 6, 2};
  // menentukan panjang array dengan menggunakan sizeof dan membaginya dengan sizeof integer
  // dengan len sebagai variabel yang menampung panjang array
  int len = sizeof(x)/sizeof(int);

  printf("Array awal: \n");
  // memanggil fungsi printArr dengan parameter x dan len
  printArr(x, len);

  printf("\nArray setelah diurutkan: \n");
  // memanggil fungsi bubleSort dengan parameter x dan len
  bubleSort(x, len);
  // memanggil fungsi printArr dengan parameter x dan len
  printArr(x, len);
  
}