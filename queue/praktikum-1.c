#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 10

typedef struct
{
	int data[MAX_DATA];
	int head;
	int tail;
} Queue;

void init(Queue *q)
{
	q->head = q->tail = -1;
}

int isEmpty(Queue *q)
{
	return q->head == -1 && q->tail == -1;
}

int isFull(Queue *q)
{
	return q->tail == MAX_DATA - 1;
}

int size(Queue *q)
{
	if (isEmpty(q))
		return 0;
	return q->tail - q->head + 1;
}

int head(Queue *q)
{
	return !isEmpty(q) ? q->data[q->head] : -1;
}

int tail(Queue *q)
{
	return !isEmpty(q) ? q->data[q->tail] : -1;
}

void enqueue(Queue *q, int value){
	if(!isFull(q)){
		if(isEmpty(q)){
			q->head++;
			q->data[++q->tail] = value;
			return;
		}
		q->data[++q->tail] = value;
		return;
	}
	printf("Queue is full\n");
}

void dequeue(Queue *q){
	if(!isEmpty(q)){
		if(q->head == 0 && q->tail == 0){
			q->head--;
			q->tail--;
			return;
		}
		for(int i = q->head + 1; i < q->tail + 1; i++){
			q->data[i - 1] = q->data[i];
		}
		q->tail--;
		return;
	}
	printf("Queue is empty\n");
}

void printQueue(Queue *q){
	if(!isEmpty(q)){
		for(int i = q->head; i < q->tail + 1; i++){
			printf("%d ", q->data[i]);
		}
		printf("\n");
		return;
	}
	printf("Queue is empty\n");
}

int main(){
	Queue q;
	init(&q);

	int opt;

	while (1)
	{
		printf("Queue\n");
		printQueue(&q);
		printf("Front: %d\n", head(&q));
		printf("Tail: %d\n", tail(&q));
    printf("Size: %d\n", size(&q));
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");
		printf(">> ");
		scanf("%d", &opt);
		if(opt == 1){
			int value;
			printf("Masukkan nilai: ");
			scanf("%d", &value);
			enqueue(&q, value);
		}
		else if(opt == 2){
			dequeue(&q);
		}
		else if(opt == 3){
			break;
		}
		else{
			printf("Pilihan tidak tersedia\n");
		}
		printf("\n");
		system("clear");
	}

	return 0;
	
}