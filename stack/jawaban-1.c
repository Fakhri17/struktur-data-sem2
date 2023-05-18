#include <stdio.h>
#include <stdlib.h>

// deklarasi maksimal ukuran stack
#define MAX_STACK_SIZE 20

// deklarasi tipe data stack
typedef struct Stack{
	// yang berisi tipe data integer dan array
	int capacity;
	int top;
	int data[MAX_STACK_SIZE];
} Stack;

// deklarasi fungsi init untuk menginisialisasi stack
void init(Stack* stack, int capacity){
	stack->capacity = capacity;
	stack->top = -1;	
}

// deklarasi fungsi isFull untuk mengecek apakah stack penuh
int isFull(Stack* stack){
	return stack->top == stack->capacity - 1;
}

// deklarasi fungsi isEmpty untuk mengecek apakah stack kosong
int isEmpty(Stack* stack){
	return stack->top == -1;
}

// deklarasi fungsi push untuk menambahkan data ke dalam stack
void push(Stack* stack, int value){
	// jika stack penuh, maka tidak bisa menambahkan data
	if (isFull(stack))
		return;
	// jika tidak penuh, maka data ditambahkan ke dalam stack dengan menambahkan +1 dari top
	stack->data[++stack->top] = value;
}

// deklarasi fungsi pop untuk mengeluarkan data dari stack
int pop(Stack* stack){
	// jika stack kosong, maka tidak bisa mengeluarkan data
	if (isEmpty(stack))
		return -1;
	// jika tidak kosong, maka data dikeluarkan dari stack dengan mengurangi -1 dari top
	return stack->data[stack->top--];
}

// deklarasi moveDisk untuk menampilkan langkah-langkah pemindahan disk
void moveDisk(char from, char last, int disk){
	printf("pindah disk %d dari '%c' ke '%c'\n", disk, from, last);
}

// deklarasi moveDisksBetweenTwoPoles untuk memindahkan disk antar tiang
void moveDisksBetweenTwoPoles(Stack *towerS, Stack *towerA, char s, char d){
	// deklarasi variabel pole1TopDisk dan pole2TopDisk
	// untuk menyimpan nilai top dari tiang 1 dan tiang 2
	int pole1TopDisk = pop(towerS);
	int pole2TopDisk = pop(towerA);

	// jika tiang 1 kosong, maka disk dari tiang 2 dipindahkan ke tiang 1
	if (pole1TopDisk == -1){
		push(towerS, pole2TopDisk);
		moveDisk(d, s, pole2TopDisk);
	}
	// jika tiang 2 kosong, maka disk dari tiang 1 dipindahkan ke tiang 2
	else if (pole2TopDisk == -1){
		push(towerA, pole1TopDisk);
		moveDisk(s, d, pole1TopDisk);
	}
	else if (pole1TopDisk > pole2TopDisk){
		push(towerS, pole1TopDisk);
		push(towerS, pole2TopDisk);
		moveDisk(d, s, pole2TopDisk);
	}
	// jika disk dari tiang 1 lebih kecil dari disk tiang 2, maka disk dari tiang 1 dipindahkan ke tiang 2
	else{
		push(towerA, pole2TopDisk);
		push(towerA, pole1TopDisk);
		moveDisk(s, d, pole1TopDisk);
	}
}

// deklarasi tohIterative yang digunakan untuk memindahkan disk secara iteratif
void tohIterative(int num_disk, Stack *towerS, Stack *towerD, Stack *towerA){
	// deklarasi variabel total_num_of_moves untuk menyimpan total jumlah pemindahan disk
	int total_num_of_moves;
	// deklarasi variabel s, d, a untuk menyimpan nama tiang
	char s = 'S', d = 'D', a = 'A';

	// jika jumlah disk genap, maka tiang tujuan dan tiang bantuan ditukar
	if (num_disk % 2 == 0){
		char temp = d;
		d = a;
		a = temp;
	}
	// rumus untuk menghitung total jumlah pemindahan disk
	total_num_of_moves = (1 << num_disk) - 1;

	// melakukan perulangan untuk menambahkan disk ke dalam tiang S
	for (int i = num_disk; i >= 1; i--)
		push(towerS, i);

	// melakukan perulangan sebanyak total jumlah pemindahan disk
	for (int i = 1; i <= total_num_of_moves; i++){
		// jika i mod 3 bernilai 1, maka pemindahan disk dilakukan dari tiang S ke tiang A
		if (i % 3 == 1)
			moveDisksBetweenTwoPoles(towerS, towerA, s, d);
		// jika i mod 3 bernilai 2, maka pemindahan disk dilakukan dari tiang S ke tiang D
		else if (i % 3 == 2)
			moveDisksBetweenTwoPoles(towerS, towerD, s, a);
		// jika i mod 3 bernilai 0, maka pemindahan disk dilakukan dari tiang A ke tiang D
		else if (i % 3 == 0)
			moveDisksBetweenTwoPoles(towerD, towerA, a, d);
	}
}

int main(){
	// deklarasi variabel towerS, towerD, towerA untuk menyimpan data stack
	Stack towerS, towerD, towerA;
	// deklarasi variabel num_disk untuk menyimpan jumlah disk
	int num_disk;
	// meminta input jumlah disk
	printf("Masukkan jumlah disk: ");
	scanf("%d", &num_disk);

	// inisialisasi stack
	init(&towerS, num_disk);
	init(&towerD, num_disk);
	init(&towerA, num_disk);

	// memanggil fungsi tohIterative untuk memindahkan disk secara iteratif
	tohIterative(num_disk, &towerS, &towerD, &towerA);
	return 0;
}