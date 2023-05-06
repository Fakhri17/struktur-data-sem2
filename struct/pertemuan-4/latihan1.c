#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int alas, tinggi, luas;
} segitiga;

void sortLuas(segitiga *s, int panjang)
{
  int i, j;
  segitiga temp;

  for (i = 0; i < panjang - 1; i++)
  {
    for (j = 0; j < panjang - 1 - i; j++)
    {
      if (s[j].luas < s[j + 1].luas)
      {
        temp = s[j];
        s[j] = s[j + 1];
        s[j + 1] = temp;
      }
    }
  }
}


int main()
{

  int panjangArray;
  scanf("%d", &panjangArray);

  segitiga s[panjangArray];

  for (int i = 0; i < panjangArray; i++)
  {
    scanf("%d", &s[i].alas);
    scanf("%d", &s[i].tinggi);
    s[i].luas = (s[i].alas * s[i].tinggi) / 2;
  }

  sortLuas(s, panjangArray);

  printf("\nOutput: \n");
  for (int i = 0; i < panjangArray; i++)
  {
    printf("%d ", s[i].alas);
    printf("%d ", s[i].tinggi);
    printf("%d\n", s[i].luas);
  }
}