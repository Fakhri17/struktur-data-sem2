#include <stdio.h>
#include <stdlib.h>

// Membuat Strutc Trapesium
typedef struct coordinatTrapesium
{
	// Membuat variabel x dan y
	// untuk menampung koordinat titik
	int x;
	int y;
} Trapesium;

int main(){
	// Membuat variabel titik A, B, C, D, E, dan F
	Trapesium A, B, C, D, E, F;

	// Membuat variabel alasA, alasB, tinggi, dan luas
	int alasA, alasB, tinggi;
	float luas;

	// Meminta inputan user untuk koordinat titik A, B, C, D, E, dan F
	printf("Masukkan koordinat titik A : ");
	scanf("%d %d", &A.x, &A.y);
	printf("Masukkan koordinat titik B : ");
	scanf("%d %d", &B.x, &B.y);
	printf("Masukkan koordinat titik C : ");
	scanf("%d %d", &C.x, &C.y);
	printf("Masukkan koordinat titik D : ");
	scanf("%d %d", &D.x, &D.y);
	printf("Masukkan koordinat titik E : ");
	scanf("%d %d", &E.x, &E.y);
	printf("Masukkan koordinat titik F : ");
	scanf("%d %d", &F.x, &F.y);

	printf("\n");
	// Menghitung alasA
	alasA = abs(A.x - B.x);
	// Menghitung alasB
	alasB = abs(E.x - F.x);
	// Menghitung tinggi
	tinggi = abs(A.y - D.y);
	// Menghitung luas trapesium
	luas = (float) (alasA + alasB) * tinggi * 0.5;
	// menampilkan hasil luas trapesium
	printf("Luas trapesium adalah: %.2f\n", luas);
	
	return 0;
}