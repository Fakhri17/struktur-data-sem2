// Belajar Array

#include <stdio.h>

int main(){
  int arr1[5] = {3,2,5,4,10};
  for (int i = 0; i < 5; i++)
  {
    printf("%d ", arr1[i]);
  }
  
  int min = arr1[0];
  for (int i = 0; i < 5; i++)
  {
    if (arr1[i] < min)
    {
      min = arr1[i];
    }
  }

  printf("%d\n", min);

  for(int i = 0; i < 5; i++){
    if(arr1[i] % 2 == 0){
      printf("%d ", arr1[i]);
    }
  }

  printf("\n");

  int arr[2][2] = {{1,2}, {3,4}};
  for (int i = 1; i >= 0; i--)
  {
    for (int j = 1; j >= 0; j--)
    {
      printf("%d ", arr[i][j]);
    }
    
  }
  
  return 0;
}