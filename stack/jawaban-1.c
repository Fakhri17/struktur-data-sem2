#include <stdio.h>

void hanoi(int n, char awal, char bantuan, char tujuan)
{
	if (n == 1)
	{
		printf("pindah disk 1 dari '%c' ke '%c'\n", awal, tujuan);
		return;
	}

	hanoi(n - 1, awal, tujuan, bantuan);
	printf("Pindah disk %d dari '%c' to '%c'\n", n, awal, tujuan);
	hanoi(n - 1, bantuan, awal, tujuan);
}

int main()
{
	int numDisks;
	printf("masukan jumlah disk: ");
	scanf("%d", &numDisks);
	hanoi(numDisks, 'S', 'A', 'D');

	return 0;
}
