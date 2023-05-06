#include <stdio.h>
#include <string.h>

struct Buku
{
  char pengarang[50];
  char judul[30];
  int tahun;
};

int main()
{

  struct Buku buku[2];
  for (int i = 0; i < 2; i++)
  {
    printf("Pengisian Buku Ke-%i \n", i + 1);
    printf("Masukkan nama pengarang : ");
    fflush(stdin);
    gets(buku[i].pengarang);
    printf("Masukkan judul: ");
    fflush(stdin);
    gets(buku[i].judul);
    
    printf("Masukkan tahun : ");
    scanf("%i", &buku[i].tahun);
    getchar();
   
  }

  printf("\nData yang telah dimasukkan adalah : \n");
  printf("| Pengarang | Judul | Tahun \n");
  for (int i = 0; i < 2; i++)
  {
    printf("| %s | %s | %i | \n", buku[i].pengarang, buku[i].judul, buku[i].tahun);
  }

  return 0;
}