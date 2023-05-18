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

void enqueue(Queue *q, int value)
{
  if (!isFull(q))
  {
    if (isEmpty(q))
    {
      q->head++;
      q->data[++q->tail] = value;
      return;
    }
    q->data[++q->tail] = value;
    return;
  }
  printf("Queue is full\n");
}

void dequeue(Queue *q)
{
  if (!isEmpty(q))
  {
    if (q->head == 0 && q->tail == 0)
    {
      q->head--;
      q->tail--;
      return;
    }
    for (int i = q->head + 1; i < q->tail + 1; i++)
    {
      q->data[i - 1] = q->data[i];
    }
    q->tail--;
    return;
  }
  printf("Queue is empty\n");
}


int main()
{
  Queue q;
  init(&q);
  int pasien[MAX_DATA] = {5, 1, 4, 8, 9, 7, 1, 2, 9, 4};
  int banyakPasien = 10;

  for (int i = 0; i < banyakPasien; i++)
  {
    enqueue(&q, pasien[i]);
  }

  for (int i = 0; i < banyakPasien; i++)
  {
    if (head(&q) <= 5)
    {
      printf("ditangani dokter umum\n");
    }
    else
    {
      printf("ditangani dokter spesialis\n");
    }
    
    dequeue(&q);
  }

  return 0;
}