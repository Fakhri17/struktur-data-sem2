#include <stdio.h>
#include <stdlib.h>

int pangkat(int x, int y){
    if(y == 0){
        return 1;
    }else{
        return x * pangkat(x, y-1);
    }
}

int main(){
    int x, y;
    printf("Masukkan bilangan: ");
    scanf("%d", &x);
    printf("Masukkan pangkat: ");
    scanf("%d", &y);
    printf("%d pangkat %d = %d", x, y, pangkat(x, y));
    return 0;
}