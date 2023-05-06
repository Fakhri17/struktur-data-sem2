#include <stdio.h>

// Membuat Strutc Pecahan
typedef struct Pecahan{
  int pembilang;
  int penyebut;
} pecahan;

// Membuat fungsi FPB
// yang mengehasilkan hasil dari FPB
int FPB(int a, int b){
  if (b == 0)
    return a;
  else
    return FPB(b, a % b);
}

// Membuat fungsi sederhana
void sederhana(pecahan *arrPecahan){
  // Membuat variabel fpb yang menampung hasil dari fungsi FPB
  int fpb = FPB(arrPecahan->pembilang, arrPecahan->penyebut);
  //melakukan pembagian pembilang dan penyebut dengan fpb
  arrPecahan->pembilang /= fpb;
  arrPecahan->penyebut /= fpb;
}

int main(){
  // Membuat array pecahan dengan tipe data struct    Pecahan
  pecahan arrPecahan[3];

  // Melakukan perulangan untuk meminta inputan user
  for (int i = 0; i < 3; i++)
  {
    printf("(pembilang, penyebut) : ");
    // Mengambil inputan user untuk pembilang dan penyebut
    scanf("%d %d", &arrPecahan[i].pembilang, &arrPecahan[i].penyebut);
  }

  printf("\n");

  // Melakukan perulangan untuk menampilkan hasil
  for (int i = 0; i < 3; i++)
  {
    // Memanggil fungsi sederhana dengan parameter arrPecahan[i]
    // yang berguna untuk menyederhanakan pecahan
    sederhana(&arrPecahan[i]);
    // Menampilkan hasil pecahan
    printf("%d/%d\n", arrPecahan[i].pembilang, arrPecahan[i].penyebut);
  }
  
  return 0;
}