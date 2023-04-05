#include <stdio.h>

int main(){
  // Deklarasi variabel array dengan panjang 70
  int arr[70];
  // Deklarasi variabel untuk menampung panjang array
  int len = sizeof(arr)/sizeof(float);
  // Deklarasi variabel untuk menampung jumlah dari semua elemen array
  float sum;
  // Deklarasi variabel untuk menampung rata-rata dari semua elemen array
  float avg;

  printf("Array : ");
  // Looping untuk mengisi array dengan angka 1 - 70
  for (int i = 0; i < len; i++)
  {
    // Mengisi array dengan angka 1 - 70
    // i + 1 karena array dimulai dari 0
    arr[i] = i + 1;
    printf("%d, ", arr[i]);
    // Menambahkan semua elemen array ke variabel sum
    sum += arr[i];
  }
  printf("\n");
  // Menghitung rata-rata dari semua elemen array
  // rumus rata-rata = jumlah / panjang
  avg = sum / len;
  // Menampilkan rata-rata dari semua elemen array
  printf("\nRata-rata dari array tersebut adalah: %.2f", avg);
  return 0;
}