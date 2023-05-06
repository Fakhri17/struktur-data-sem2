#include <stdio.h>

// Membuat Strutc Laba
typedef struct {
  // Membuat variabel nama, modal, dan jual
  // untuk menyimpan data nama, modal, dan jual
  char nama[20];
  int modal;
  int jual;
}Laba;

int main(){
  // Membuat variabel laba dan margin
  Laba laba;
  int margin;
  // Meminta inputan user untuk nama, modal, dan jual
  printf("Nama : ");
  // Menggunakan gets untuk mengambil inputan user
  gets(laba.nama);
  printf("Modal : ");
  // Menggunakan scanf untuk mengambil inputan modal dan jual
  scanf("%d", &laba.modal);
  printf("Jual : ");
  scanf("%d", &laba.jual);

  // Menghitung margin yang rumusnya adalah jual - modal
  margin = laba.jual - laba.modal;

  // menampilkan hasil margin
  printf("\nMargin adalah: %d\n", margin);

  return 0;
}