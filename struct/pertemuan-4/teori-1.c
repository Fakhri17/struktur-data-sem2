#include <stdio.h>

typedef struct
{
  int umur;
  char *nama;
}coba;

int main(){
  coba variabel[2];

  variabel[0].umur = 10;
  variabel[0].nama = "A";

  variabel[1].umur = 20;
  variabel[1].nama = "B";

  for (int i = 0; i < 2; i++)
  {
    printf("%d %s\n", variabel[i].umur, variabel[i].nama);
  }
}
