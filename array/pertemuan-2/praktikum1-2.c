#include <stdio.h>

int tambah(int a, int b)
{
  int hasil = a + b;
  return hasil;
}

void tambah_5(int *angka)
{
  *angka = *angka + 5;
}

// prosedur dengan argumen pointer array
void printArray(int *angka, int panjang)
{
  for (int i = 0; i < panjang; i++)
  {
    printf("%d ", *(angka + i));
  }
}



int main()
{
  int arr[5] = {1, 2, 3, 4, 5};
  int panjang = sizeof(arr) / sizeof(arr[0]);
  int hasil = tambah(1, 2);
  printf("hasil = %d", hasil);

  printf("\n\n");
  printf("Prosedur dengan argumen pointer\n");
  int nilai = 90;

  printf("Nilai awal adalah %d", nilai);

  /* memanggil prosedur tambah_5 dengan argumen disertai simbol ampersand `&` yang
  digunakan untuk meneruskan alamat variabel nilai ke dalam prosedur tambah_5 */
  tambah_5(&nilai);
  printf("\nNilai setelah ditambah adalah %d\n", nilai);

  // printf("\n\n");
  printArray(arr, panjang);
  

}