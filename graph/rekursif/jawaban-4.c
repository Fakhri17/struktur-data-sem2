#include <stdio.h>

// fungsi rekursif untuk menghitung jumlah digit dari sebuah bilangan
int hitungJumlahDigit(int n)
{
  // jika bilangan tidak sama dengan 0, maka lakukan rekursif
  // dengan membagi bilangan dengan 10
  // jika bilangan sama dengan 0, maka kembalikan nilai 0
  if (n != 0) return 1 + hitungJumlahDigit(n / 10);
  return 0;
}


int main()
{
  int bilangan;
  // input bilangan
  printf("Masukkan bilangan bulat: ");
  scanf("%d", &bilangan);

  // memanggil fungsi rekursif untuk menghitung jumlah digit dari bilangan
  int jumlahDigit = hitungJumlahDigit(bilangan);
  printf("Jumlah digit dari %d adalah %d\n", bilangan, jumlahDigit);

  return 0;
}
