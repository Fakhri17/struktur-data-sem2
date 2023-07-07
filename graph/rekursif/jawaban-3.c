#include <stdio.h>

// Fungsi rekursif untuk mencari nilai terbesar dalam array
int cariNilaiTerbesar(int arr[], int n)
{
  // Base case: Jika array hanya memiliki satu elemen, kembalikan nilai elemen tersebut
  if (n == 1){
    return arr[0];
  }
  // Recursive case: Cari nilai terbesar dalam array kecuali elemen pertama,
  // dan bandingkan dengan elemen pertama
  int max = cariNilaiTerbesar(arr, n - 1);
  if (arr[n - 1] > max){
    return arr[n - 1];
  }   
  else{
    return max;
  }
}

int main()
{
  
  int panjang;
  // input panjang arrray
  printf("Masukkan banyak array yang di inginkan: ");
  scanf("%d", &panjang);

  // deklarasi array
  int arr[panjang];
  // input nilai array sebanyak nilai panjang
  for (int i = 0; i < panjang; i++)
  {
    printf("Masukkan nilai array ke-%d: ", i + 1);
    scanf("%d", &arr[i]);
  }
  // memanggil fungsi rekursif untuk mencari nilai terbesar dalam array
  int nilaiTerbesar = cariNilaiTerbesar(arr, panjang);
  printf("\nNilai terbesar dalam array adalah: %d\n", nilaiTerbesar);

  return 0;
}
