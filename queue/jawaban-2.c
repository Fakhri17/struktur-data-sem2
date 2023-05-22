#include <stdio.h>
#include <stdlib.h>

// deklarasi maksimal data yang dapat disimpan
#define MAX_DATA 26

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
// Deklarasi size untuk menghitung banyak data yang ada di queue
int size(Queue *q)
{
  // jika queue kosong, maka size = 0
  if (isEmpty(q))
    return 0;
  // jika tidak, maka size = tail - head + 1
  return q->tail - q->head + 1;
}
// Deklarasi head untuk mengambil data pertama di queue
int head(Queue *q)
{
  // jika queue tidak kosong, maka return data di index head, jika tidak return -1
  return !isEmpty(q) ? q->data[q->head] : -1;
}
// Deklarasi tail untuk mengambil data terakhir di queue
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
      // set head + 1 dan data di index tail +1 = value
      q->head++;
      q->data[++q->tail] = value;
      return;
    }
    // jika tidak, maka data di index tail + 1 = value
    q->data[++q->tail] = value;
    return;
  }
  // jika penuh, maka tampilkan pesan
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
 
int main()
{
  // deklarasi queue
  Queue q;
  // inisialisasi queue
  init(&q);
  // deklarasi variabel untuk menyimpan string
  char str[50];
  // input string
  printf("Input string: ");
  gets(str);

  // deklarasi variabel untuk menyimpan index karakter tunggal
  // -1 ketika tidak ada karakter tunggal
  int charTunggal = -1;
  // deklarasi array untuk menyimpan jumlah alphabet
  int arr[26] = {0};
  // perulangan untuk menghitung jumlah alphabet
  for (int i = 0; str[i] != '\0'; i++)
  {
    // increment jumlah alphabet di index yang sesuai
    arr[str[i] - 'a']++;
  }
  // perulangan untuk mencari index karakter tunggal
  for (int i = 0; str[i] != '\0'; i++)
  {
    // jika jumlah alphabet di index yang sesuai == 1, maka enqueue index
    if (arr[str[i] - 'a'] == 1)
    {
      // enqueue index
      enqueue(&q, i);
    }
  }
  // jika queue tidak kosong, maka dequeue index
  if (!isEmpty(&q))
  {
    // charTunggal = head queue karena head queue adalah index karakter tunggal
    charTunggal = head(&q);
    // dequeue index kaarena sudah tidak digunakan
    dequeue(&q);
  }
  // tampilkan index karakter tunggal
  printf("%d\n", charTunggal);

  return 0;
}
