#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Fungsi untuk mengecek apakah sebuah kata adalah palindrom
bool is_palindrome(char *kata, int awal, int akhir)
{
  // jika indeks awal sudah melebihi atau sama dengan indeks akhir
  if (awal >= akhir){
    // kata tersebut adalah palindrom
    return true;
  }
  // jika karakter pada indeks awal tidak sama dengan karakter pada indeks akhir
  if (kata[awal] != kata[akhir]){
    return false;
  }
  // memanggil fungsi rekursif untuk karakter selanjutnya
  is_palindrome(kata, awal + 1, akhir - 1);
}

// Fungsi main
int main()
{
  char kata[100];
  // input kata
  printf("Masukkan kata: ");
  scanf("%s", kata);
  // mengukur panjang kata
  int panjangKata = strlen(kata);
  // memanggil fungsi untuk mengecek apakah kata tersebut adalah palindrom
  is_palindrome(kata, 0, panjangKata - 1) ? printf("Kata %s adalah palindrom\n", kata) : printf("Kata %s bukan palindrom\n", kata);
  return 0;
}
