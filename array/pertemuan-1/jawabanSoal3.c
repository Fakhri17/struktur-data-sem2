#include <stdio.h>

int main(){
  
  // INISIALISASI ARRAY 2 dimensi dengan nilai yang sudah ditentukan
  // dimana arr sebagai sebuah variabel array 2 dimensi bertipe data integer dengan 3 baris dan 2 kolom
  int arr[3][2] = {{3,6},{9,8},{15,10}};
  // variabel cari sebagai variabel yang menampung nilai yang ingin dicari
  int cari;
  // variabel flag sebagai variabel penanda jika element ditemukan atau tidak
  int flag = 0;

 
  printf("Array: ");
  // loop pertama untuk memanggil baris
  for (int i = 0; i < 3; i++)
  {
    // loop kedua untuk memanggil kolom
    for (int j = 0; j < 2; j++)
    {
      // untuk menampilkan element dari array
      printf("%d, ", arr[i][j]);
    }
  }

  // input element yang ingin dicari
  printf("\nMasukkan elements yang ingin indeksnya: ");
  scanf("%d", &cari);

  // loop pertama untuk memanggil baris
  for (int i = 0; i < 3; i++)
  {
    // loop kedua untuk memanggil kolom
    for (int j = 0; j < 2; j++)
    {
      // jika element yang dicari sama dengan element yang ada di array
      // maka akan menampilkan indeks dari element tersebut
      // dan mengubah nilai flag menjadi 1
      if (cari == arr[i][j])
      {
        printf("\nElemen %d berada di indeks[%d][%d]\n", cari, i, j);
        flag = 1;
        break;
      }
    }
  }

  // jika array tidak ditemukan maka akan menampilkan pesan
  if (flag == 0)
  {
    printf("\nTidak ada elemen tersebut di dalam array\n");
  }

  return 0;
}