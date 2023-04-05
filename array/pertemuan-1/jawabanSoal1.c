#include <stdio.h>

int main(){

  // INISIALISASI ARRAY dengan nilai yang sudah ditentukan
  // dimana x sebagai sebuah variabel array bertipe data integer
   int x[3][2] = {{3,6},{9,8},{15,10}};

   //loop pertama untuk memanggil baris
   for (int i = 0; i < 3; i++)
   {
    //loop kedua untuk memanggil kolom
    for (int j = 0; j < 2; j++){
      // untuk menampilkan nilai dari array
      // variabel i berperan untuk mengetahui baris
      // variabel j berperan untuk mengetahui kolom
      // x[i][j] digunakan untuk menampilkan nilai dari array
      printf("Nilai array x[%d][%d] adalah : %d\n", i, j, x[i][j]);
    }

   }
   
   return 0;
}