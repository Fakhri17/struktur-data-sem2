#include <stdio.h>
#include <stdlib.h>

// membuat fungsi koboiImaginaryChess untuk menampilkan papan catur
// fungsi koboImaginaryChess memiliki 4 parameter
// i dan j adalah posisi bidak kuda
void koboImaginaryChess(int i, int j, int size, int *chessBoard)
{
	// melakukan perulangan sebanyak size
	for (int a = 0; a < size; a++)
	{
		// melakukan perulangan sebanyak size
		for (int b = 0; b < size; b++)
		{
			// setiap elemen pada array chessBoard diisi dengan nilai 0
			*(chessBoard + a * size + b) = 0;
		}
	}

	// membuat array move untuk menyimpan langkah-langkah yang dapat dilakukan oleh kuda
	int move[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
	// membuat variabel upDown dan leftRight untuk menyimpan nilai perpindahan kuda
	int upDown, leftRight;
	// melakukan perulangan sebanyak size
	for (int a = 0; a < size; a++)
	{
		// menghitung nilai upDown dan leftRight
		upDown = i + move[a][0];
		leftRight = j + move[a][1];
		// melakukan pengecekan apakah nilai upDown dan leftRight berada di dalam papan catur
		if (upDown >= 0 && upDown < size && leftRight >= 0 && leftRight < size)
		{
			// jika nilai upDown dan leftRight berada di dalam papan catur
			// maka nilai elemen pada array chessBoard di posisi upDown dan leftRight diisi dengan nilai 1
			*(chessBoard + upDown * size + leftRight) = 1;
		}
	}

	// melakukan perulangan sebanyak size
	for (int a = 0; a < size; a++)
	{
		// melakukan perulangan sebanyak size
		for (int b = 0; b < size; b++)
		{
			// menampilkan nilai elemen pada array chessBoard
			printf("%d", *(chessBoard + a * size + b));
		}
		// membuat baris baru
		printf("\n");
	}
}

int main()
{
	// deklarasi array 2 dimensi bernama board dengan ukuran 8x8
	int board[8][8];
	// deklarasi variabel i dan j untuk menyimpan posisi bidak kuda
	int i, j;
	// input posisi bidak kuda
	scanf("%d %d", &i, &j);
	// panggil fungsi koboImaginaryChess dengan mengirim nilai i, j, 8, dan board[0]
	koboImaginaryChess(i, j, 8, board[0]);
	
	return 0;
}