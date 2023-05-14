#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20

typedef struct Stack{
	int capacity;
	int top;
	int data[MAX_STACK_SIZE];
} Stack;

void init(Stack* stack, int capacity){
	stack->capacity = capacity;
	stack->top = -1;	
}

int isFull(Stack* stack){
	return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack){
	return stack->top == -1;
}

void push(Stack* stack, int value){
	if (isFull(stack))
		return;
	stack->data[++stack->top] = value;
}

int pop(Stack* stack){
	if (isEmpty(stack))
		return -1;
	return stack->data[stack->top--];
}

void moveDisk(char from, char last, int disk){
	printf("pindah disk %d dari '%c' ke '%c'\n", disk, from, last);
}

void moveDisksBetweenTwoPoles(Stack *towerS, Stack *towerA, char s, char d){
	int pole1TopDisk = pop(towerS);
	int pole2TopDisk = pop(towerA);

	if (pole1TopDisk == -1){
		push(towerS, pole2TopDisk);
		moveDisk(d, s, pole2TopDisk);
	}
	else if (pole2TopDisk == -1){
		push(towerA, pole1TopDisk);
		moveDisk(s, d, pole1TopDisk);
	}
	else if (pole1TopDisk > pole2TopDisk){
		push(towerS, pole1TopDisk);
		push(towerS, pole2TopDisk);
		moveDisk(d, s, pole2TopDisk);
	}
	else{
		push(towerA, pole2TopDisk);
		push(towerA, pole1TopDisk);
		moveDisk(s, d, pole1TopDisk);
	}
}

void tohIterative(int num_disk, Stack *towerS, Stack *towerD, Stack *towerA){
	int total_num_of_moves;
	char s = 'S', d = 'D', a = 'A';

	if (num_disk % 2 == 0){
		char temp = d;
		d = a;
		a = temp;
	}

	total_num_of_moves = (1 << num_disk) - 1;

	for (int i = num_disk; i >= 1; i--)
		push(towerS, i);

	for (int i = 1; i <= total_num_of_moves; i++){
		if (i % 3 == 1)
			moveDisksBetweenTwoPoles(towerS, towerA, s, d);
		else if (i % 3 == 2)
			moveDisksBetweenTwoPoles(towerS, towerD, s, a);
		else if (i % 3 == 0)
			moveDisksBetweenTwoPoles(towerD, towerA, a, d);
	}
}

int main(){
	Stack towerS, towerD, towerA;
	int num_disk;
	printf("Masukkan jumlah disk: ");
	scanf("%d", &num_disk);

	init(&towerS, num_disk);
	init(&towerD, num_disk);
	init(&towerA, num_disk);

	tohIterative(num_disk, &towerS, &towerD, &towerA);
	return 0;
}