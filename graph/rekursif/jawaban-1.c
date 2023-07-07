#include <stdio.h>
#include <string.h>

// Fungsi untuk mencetak semua subsequences dari sebuah kata
void subsequences(char *kata, int panjangKata, int index, char *temp)
{
  // menampilkan kata kosong dan kata yang sudah terbentuk
  printf("\"%s\", ", temp);
  // melakukan looping untuk semua karakter yang tersisa
  for (int i = index; i < panjangKata; i++)
  {
    // mengukur panjang string sementara dari temp
    int len = strlen(temp);
    temp[len] = kata[i];
    // menambahkan null character di akhir string
    temp[len + 1] = '\0';
    // memanggil fungsi rekursif untuk karakter selanjutnya
    subsequences(kata, panjangKata, i + 1, temp);
    temp[len] = '\0';
  }
}

// Fungsi main
int main()
{
  // deklarasi dan input kata
  char kata[20];
  printf("Masukkan kata: ");
  scanf("%s", kata);
  // deklarasi penampung sementara
  char temp[20] = "";
  // memanggil fungsi untuk mencetak semua subsequences
  subsequences(kata, strlen(kata), 0, temp);
  return 0;
}
