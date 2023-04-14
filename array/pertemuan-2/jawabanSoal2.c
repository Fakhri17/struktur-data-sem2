#include <stdio.h>

// membuat fungsi arrayMean untuk menghitung rata-rata dari array
// fungsi arrayMean memiliki 2 parameter arr dan n
// tipe data float karena rata-rata bisa berupa bilangan pecahan
float arrayMean(int *arr, int n)
{
	// inisialisasi variabel sum dengan nilai 0 terlebih dahulu
	float sum = 0;
	// lakukan perulangan sebanyak n
	for (int i = 0; i < n; i++)
	{
		// setiap perulangan, tambahkan nilai dari array ke variabel sum
		sum += *(arr + i);
	}
	// setelah perulangan selesai, maka nilai sum adalah jumlah dari semua nilai array
	// lalu bagi dengan n untuk mendapatkan rata-rata
	return sum / n;
}

int main()
{
	// deklarasi variabel n untuk menyimpan panjang array
	int n;
	// input variabel n
	scanf("%d", &n);
	// deklarasi array dengan panjang n
	int arr[n];
	// lakukan perulangan sebanyak n
	for (int i = 0; i < n; i++)
	{
		// setiap perulangan, input nilai array ke-i
		scanf("%d", &arr[i]);
	}
	// panggil fungsi arrayMean dengan mengirim nilai array dan n
	// tampikan nilai yang dikembalikan oleh fungsi arrayMean
	printf("%.2f", arrayMean(arr, n));
	return 0;
}