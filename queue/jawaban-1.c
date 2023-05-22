#include <stdio.h>
#include <stdlib.h>

// deklarasi maksimal data yang dapat disimpan
#define MAX_DATA 10

// deklarasi struct Queue
typedef struct
{
  // deklarasi tipe data dan variabel untuk menyimpan data queue
  // data untuk menyimpan data array, head untuk menyimpan index awal, tail untuk menyimpan index akhir
  int data[MAX_DATA];
  int head;
  int tail;
} Queue;

// deklrasi init untuk menginisialisasi queue
void init(Queue *q)
{
  // set head dan tail ke -1 untuk menandakan queue kosong
  q->head = q->tail = -1;
}
// deklarasi isEmpty untuk mengecek apakah queue kosong atau tidak
int isEmpty(Queue *q)
{
  // jika head dan tail masih -1, maka queue kosong
  return q->head == -1 && q->tail == -1;
}
// deklarasi isFull untuk mengecek apakah queue penuh atau tidak
int isFull(Queue *q)
{
  // jika index tail == MAX_DATA - 1, maka queue penuh
  return q->tail == MAX_DATA - 1;
}
// deklarasi size untuk menghitung banyak data yang ada di queue
int size(Queue *q)
{
  // jika queue kosong, maka size = 0
  if (isEmpty(q))
    return 0;
  // jika tidak, maka size = tail - head + 1
  return q->tail - q->head + 1;
}
// deklarasi head untuk mengambil data pertama di queue
int head(Queue *q)
{
  // jika queue tidak kosong, maka return data di index head, jika tidak return -1
  return !isEmpty(q) ? q->data[q->head] : -1;
}
// deklarasi tail untuk mengambil data terakhir di queue
int tail(Queue *q)
{
  // jika queue tidak kosong, maka return data di index tail, jika tidak return -1
  return !isEmpty(q) ? q->data[q->tail] : -1;
}
// deklarasi enqueue untuk menambah data ke queue
void enqueue(Queue *q, int value)
{
  // jika queue tidak penuh, maka lakukan penambahan data
  if (!isFull(q))
  {
    // jika queue kosong
    if (isEmpty(q))
    {
      // tambahkan head + 1 dan data di index tail + 1 = value
      q->head++;
      q->data[++q->tail] = value;
      return;
    }
    // jika queue tidak kosong, maka tambahkan data di index tail + 1 = value
    q->data[++q->tail] = value;
    return;
  }
  // jika queue penuh, maka print queue penuh
  printf("Queue is full\n");
}
// deklarasi dequeue untuk menghapus data di queue
void dequeue(Queue *q)
{
  // jika queue tidak kosong, maka lakukan penghapusan data
  if (!isEmpty(q))
  {
    // jika head == tail == 0, maka set head dan tail ke -1
    if (q->head == 0 && q->tail == 0)
    {
      q->head--;
      q->tail--;
      return;
    }
    // jika tidak, maka lakukan pergeseran data ke kiri dengan perulangan
    for (int i = q->head + 1; i < q->tail + 1; i++)
    {
      // data di index i - 1 = data di index i
      q->data[i - 1] = q->data[i];
    }
    // set tail ke tail - 1 untuk menghapus data terakhir
    q->tail--;
    return;
  }
  // jika queue kosong, maka print queue kosong
  printf("Queue is empty\n");
}
// deklarasi compareSwitch untuk membandingkan data di queue 1 dan queue 2
// yang digunakan untuk membandingkan data student dan bubur
void compareSwitch(Queue *q, Queue *q2)
{
  // bikin variabel flag untuk ngecek apakah masih ada yang sama atau tidak
  // kalau masih ada yang sama, flag = 1 kalau tidak flag = 0
  int flag = 1;

  // selama queue tidak kosong dan flag = 1, maka lakukan perulangan
  while (!isEmpty(q) && !isEmpty(q2) && flag)
  {
    // set flag = 0 supaya kalau tidak ada yang sama, maka perulangan berhenti
    flag = 0;

    // kalau head dari q dan q2 sama, maka dequeue keduanya
    if (head(q) == head(q2))
    {
      dequeue(q);
      dequeue(q2);
    }
    // kalau tidak sama, simpan head dari q ke variabel temp, dequeue q, lalu enqueue temp ke q
    else
    {
      int temp = head(q);
      dequeue(q);
      enqueue(q, temp);
    }

    // cek apakah ada yang sama antara head dari q dan q2
    for (int i = 0; i < size(q); i++)
    {
      // jika masih ada yang sama, maka flag = 1
      if (q->data[i] == head(q2))
      {
        flag = 1;
      }
    }
  }
}

int main()
{
  // buat queue q dan q2
  // q untuk menyimpan data student, q2 untuk menyimpan data bubur
  Queue q, q2;
  // inisialisasi queue q dan q2
  init(&q);
  init(&q2);
  // buat variabel banyakData untuk menyimpan banyak data yang akan diinput
  int banyakData;
  // input banyakData 
  printf("Banyak data: ");
  scanf("%d", &banyakData);
  // buat array student dan bubur untuk menyimpan data student dan bubur
  // sepajang banyakData
  int student[banyakData];
  int bubur[banyakData];

  printf("Student: ");
  // lakukan perulangan sebanyak banyakData untuk input data student
  for (int i = 0; i < banyakData; i++)
  {
    scanf("%d", &student[i]);
    // setiap data yang diinput, enqueue ke queue q
    enqueue(&q, student[i]);
  }

  printf("Bubur: ");
  // lakukan perulangan sebanyak banyakData untuk input data bubur
  for (int i = 0; i < banyakData; i++)
  {
    scanf("%d", &bubur[i]);
    // setiap data yang diinput, enqueue ke queue q2
    enqueue(&q2, bubur[i]);
  }
  // panggil fungsi compareSwitch untuk membandingkan data student dan bubur
  compareSwitch(&q, &q2);
  // print banyak data yang tersisa di queue q
  printf("%d\n", size(&q));
}