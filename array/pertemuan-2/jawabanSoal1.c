#include <stdio.h>

// membuat fungsi greatestOf untuk mencari nilai terbesar dari 4 bilangan
// fungsi greatestOf memilikik 4 parameter 
int greatestOf(int a, int b, int c, int d) {
	// jika salah satu bilangan negatif, maka return -1
	if (a < 0 || b < 0 || c < 0 || d < 0) {
		return -1;
	}
	// jika semua bilangan positif, maka cari nilai terbesar
	// inisialisasi nilai awal dari variabel max dengan nilai a
	int max = a;
	// jika nilai b lebih besar dari nilai max, maka nilai max diisi dengan nilai b
	if (b > max) max = b;
	// jika nilai c lebih besar dari nilai max, maka nilai max diisi dengan nilai c
	if (c > max) max = c;
	// jika nilai d lebih besar dari nilai max, maka nilai max diisi dengan nilai d
	if (d > max) max = d;
	// return nilai max
	return max;
}

int main(){
	// deklarasi variabel a, b, c, d yang nantinya untuk mengirim nilai pada fungsi greatestOf
	int a, b, c, d;
	// input nilai a, b, c, d
	scanf("%d %d %d %d", &a, &b, &c, &d);
	// panggil fungsi greatestOf dengan mengirim nilai a, b, c, d
	// simpan nilai yang dikembalikan oleh fungsi greatestOf pada variabel max
	int max = greatestOf(a, b, c, d);
	// jika nilai max sama dengan -1, maka tampilkan pesan "Harus bilangan positif semua"
	if (max == -1) {
		printf("Harus bilangan positif semua");
	}
	// jika nilai max tidak sama dengan -1, maka tampilkan nilai max 
	else {
		printf("%d", max);
	}
	return 0;
}