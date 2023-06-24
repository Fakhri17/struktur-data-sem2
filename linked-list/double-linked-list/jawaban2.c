#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// deklarasi struct node untuk menampung data daouble linked list
// dengan 3 variabel yaitu nama, next, dan prev
typedef struct node
{
  char nama[255];
  struct node *next;
  struct node *prev;
} Node;

// membuat fungsi untuk membuat node baru dengan paramater data untuk mendapatkan nilai
Node *createNode(char *nama)
{
  // untuk newnode digunakan untuk membuat node
  // untuk variabel newnode->data untuk menampung nilai
  // prev dan next kita buat null
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->nama, nama);
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Membuat fungsi insert first dengan paramater Node sama val untuk mendapatkan nilai
Node *insertFirst(Node *head, char *nama)
{
  // newnode untuk dengan fungsi createnode untuk membuat node
  Node *newNode = createNode(nama);
  // cek jika head null maka head = newnode
  if (head == NULL)
  {
    head = newNode;
  }
  // jika tidak maka newnode->next = head
  // dan head->prev dan head = newnode
  else
  {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  return head;
}

// membuat fungsi delete nama dari antrian
Node *deleteByName(Node *head, char *nama)
{
  // membuat variabel curr untuk menampung head
  Node *curr = head;
  // cek jika head null maka return null
  if (head == NULL)
  {
    return NULL;
  }
  // jika nama sama dengan head->nama
  else if (strcmp(head->nama, nama) == 0)
  {
    // jika head->next null maka free head dan head null
    if (head->next == NULL)
    {
      free(head);
      head = NULL;
    }
    // jika tidak maka head = head->next dan free head->prev dan head->prev null
    else
    {
      head = head->next;
      free(head->prev);
      head->prev = NULL;
    }
  }
  // jika tidak maka cek selama curr tidak null dan curr->nama tidak sama dengan nama
  else
  {
    // melakukan looping selama curr tidak null dan curr->nama tidak sama dengan nama
    while (curr != NULL && strcmp(curr->nama, nama) != 0)
    {
      curr = curr->next;
    }
    // jika curr null maka nama tidak ada
    if (curr == NULL)
    {
      printf("Nama tidak ada\n");
      system("pause");
    }
    // jika curr->next null maka curr->prev->next null dan free curr
    else if (curr->next == NULL)
    {
      curr->prev->next = NULL;
      free(curr);
    }
    // jika tidak maka curr->prev->next = curr->next dan curr->next->prev = curr->prev dan free curr
    else
    {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      free(curr);
    }
  }
  return head;
}

// membuat fungsi cek antrian dengan paramater head dan nama
void cekAntrian(Node *head, char *nama)
{
  // membuat variabel curr untuk menampung head dan count untuk menampung jumlah antrian
  Node *curr = head;
  int count = 0;
  // cek jika head null maka tidak ada antrian
  if (head == NULL)
  {
    printf("Tidak ada antrian\n");
  }
  // jika nama sama dengan head->nama maka antrian atas nama nama
  else
  {
    // melakukan looping selama curr tidak null dan curr->nama tidak sama dengan nama
    while (curr != NULL && strcmp(curr->nama, nama) != 0)
    {
      curr = curr->next;
    }
    // jika curr null maka nama tidak ada
    if (curr == NULL)
    {
      printf("Nama tidak ada\n");
      system("pause");
    }
    // jika tidak lakukan looping selama curr->next tidak null
    // maka tampilkan antriannya
    else
    {
      while (curr->next != NULL)
      {
        curr = curr->next;
        count++;
      }
      printf("Antrian atas nama %s kurang %d antrian lagi\n", nama, count);
      system("pause");
    }
  }
}

// membuat fungsi print dengan skema FIFO 
void fifoPrint(Node *head)
{
  // membuat node variabel curr untuk menerima head dan count untuk menampung jumlah antrian
  Node *curr = head;
  int count = 0;
  // jika curr->next tidak sama dengan null maka curr = curr->next
  if(curr == NULL){
    printf("Tidak ada antrian\n");
  }
  // jika tidak maka lakukan looping selama curr->next tidak null
  else{
    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    // jika curr !=null maka melakukan output
    // dan menampilkan nama dan nomor antrian
    while (curr != NULL)
    {
      count++;
      printf("[%d] nama : %s \n", count, curr->nama);
      curr = curr->prev;
    }
  }
}

// program utama
int main()
{
  Node *head = NULL;
  int pilihan;
  char nama[255];

  while (1)
  {
    system("cls");
    printf("Daftar pasien dalam antrian: \n");
    fifoPrint(head);
    printf("\n");
    printf("1. Tambah Antrian\n");
    printf("2. Hapus Antrian ( nama antrian )\n");
    printf("3. Cek Antrian\n");
    printf("4. Exit\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);
    getchar();
    if (pilihan == 1)
    {
      printf("Masukkan nama: ");
      scanf("%s", nama);
      getchar();
      head = insertFirst(head, nama);
    }
    else if (pilihan == 2)
    {
      printf("Masukkan nama: ");
      scanf("%s", nama);
      getchar();
      head = deleteByName(head, nama);
    }
    else if (pilihan == 3)
    {
      printf("Masukkan nama: ");
      scanf("%s", nama);
      getchar();
      cekAntrian(head, nama);
    }
    else if (pilihan == 4)
    {
      printf("Program selesai, sampai jumpa!\n");
      system("pause");
      exit(0);
      break;
    }
    else{
      printf("Pilihan tidak tersedia\n");
      system("pause");
    }
  }
  return 0;
}