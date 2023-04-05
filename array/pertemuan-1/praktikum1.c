#include <stdio.h>

int main()
{
  int total = 0;
  int total1 = 1;
  char arr[3][10] = {"Hallo", "Gojo", "Satoru"};
  char arrString[] = "nama saya joko widodo";
  // karena di dalam bahasa C tidak terdapat tipe data String maka digunakan tipe data char
  // dengan begitu batas character dalam suatu array adalah 10 
  // for (int i = 0; i < 3; i++)
  // {
  //   for (int j = 0; j < 10; j++)
  //   {
  //     if (arr[i][j] != 'o')
  //     {
  //       printf("%c", arr[i][j]);
  //     }
  //   }
  //   printf("\n");
    
  // }
  
  for (int i = 0; i < sizeof(arrString)/sizeof(char); i++)
  {
    if (arrString[i] != ' ')
    {
      total++;
    }
    if (arrString[i] == ' ')
    {
      total1++;
    }
    
    printf("%c", arrString[i]);
  }
  
  printf("\nJumlah char tanpa spasi = %d", total-1);
  printf("\nJumlah Kata = %d", total1);
}