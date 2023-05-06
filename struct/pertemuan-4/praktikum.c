#include <stdio.h>

struct Buku{
  int id_buku;
  char *judul;
  int tahun;
};

struct perpustakaan
{
  char *nama;
  char *alamat;
  struct Buku buku;
};


int main (){
  struct Buku buku1, buku2;

  buku1.id_buku = 1;
  buku1.judul = "Buku 1";
  buku1.tahun = 2020;

  buku2.id_buku = 2;
  buku2.judul = "Buku 2";
  buku2.tahun = 2021;

  printf("Buku 1\n");
  printf("ID Buku: %d\n", buku1.id_buku);
  printf("Judul: %s\n", buku1.judul);
  printf("Tahun: %d\n", buku1.tahun);
  printf("\n");
  printf("Buku 2\n");
  printf("ID Buku: %d\n", buku2.id_buku);
  printf("Judul: %s\n", buku2.judul);
  printf("Tahun: %d\n", buku2.tahun);

  return 0;
}