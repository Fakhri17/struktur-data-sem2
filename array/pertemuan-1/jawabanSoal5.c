#include <stdio.h>

int main(){

  // Deklarasi jumlah lantai yang ada 
  int lantai[10] = {1,2,3,4,5,6,7,8,9,10};
  // Deklarasi variabel untuk menampung panjang array
  int len = sizeof(lantai)/sizeof(int);
  // Deklarasi variabel untuk menampung inputan lantai yang ingin dituju
  int inputLantai;
  // Deklarasi variabel untuk menampung index dari lantai yang ingin dituju
  int baseIndex;

  // Menginputkan lantai yang ingin dituju
  printf("Masukkan lantai yang ingin anda tuju: ");
  scanf("%d", &inputLantai);

  // Looping untuk mencari index dari lantai yang ingin dituju
  for (int i = 0; i < len; i++)
  {
    // Jika lantai yang ingin dituju ditemukan
    if (lantai[i] == inputLantai)
    {
      // Menyimpan index dari lantai yang ingin dituju ke variabel baseIndex
      baseIndex = i;
      // Menghentikan looping karena lantai yang ingin dituju sudah ditemukan
      break;
    }
  }

  // jika baseIndex kurang dari 2
  if (baseIndex < 2)
  {
    printf("Urutan lantai : ");
    // Looping untuk menampilkan urutan lantai dari lantai 1 - 5
    // dimana i = 0 karena index array dimulai dari 0 dan i < 5 karena hanya 5 lantai yang ditampilkan
    for (int i = 0; i < 5; i++)
    {
      printf("%d ", lantai[i]);
    }
  }
  // jika baseIndex lebih dari panjang array - 3
  else if (baseIndex > len - 3)
  {
    printf("Urutan lantai : ");
    // i = len - 5 karena kita menampilkan 5 lantai terakhir dan i < len karena panjang array adalah len
    for (int i = len - 5; i < len; i++)
    {
      printf("%d ", lantai[i]);
    }
  }
  // jika baseIndex tidak memenuhi kondisi diatas
  else
  {
    printf("Urutan lantai : ");
    // Looping untuk menampilkan urutan lantai dari 2 lantai sebelum lantai yang ingin dituju sampai 2 lantai setelah lantai yang ingin dituju
    // dimana i = baseIndex - 2 karena kita menampilkan 2 lantai sebelum lantai yang ingin dituju dan i < baseIndex + 3 
    // karena kita menampilkan 2 lantai setelah lantai yang ingin dituju
    for (int i = baseIndex - 2; i < baseIndex + 3; i++)
    {
      printf("%d ", lantai[i]);
    }
  }
  
  return 0;
}