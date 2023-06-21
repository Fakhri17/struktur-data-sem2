#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
  char nama[255];
  struct node *next;
  struct node *prev;
} Node;

Node *createNode(char *nama)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->nama, nama);
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Insert first

Node *insertFirst(Node *head, char *nama)
{
  Node *newNode = createNode(nama);
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  return head;
}

// Deleted by name
// display nama tidak ada if name not found
Node *deleteByName(Node *head, char *nama)
{
  Node *curr = head;
  if (head == NULL)
  {
    return NULL;
  }
  else if (strcmp(head->nama, nama) == 0)
  {
    if (head->next == NULL)
    {
      free(head);
      head = NULL;
    }
    else
    {
      head = head->next;
      free(head->prev);
      head->prev = NULL;
    }
  }
  else
  {
    while (curr != NULL && strcmp(curr->nama, nama) != 0)
    {
      curr = curr->next;
    }
    if (curr == NULL)
    {
      printf("Nama tidak ada\n");
      system("pause");
    }
    else if (curr->next == NULL)
    {
      curr->prev->next = NULL;
      free(curr);
    }
    else
    {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      free(curr);
    }
  }
  return head;
}


// Cek Antrian berdasarkan inputan nama
// Example output: Antrian atas nama fakhri kurang 3 antrian lagi
// count from bellow to top

void cekAntrian(Node *head, char *nama)
{
  Node *curr = head;
  int count = 0;
  if (head == NULL)
  {
    printf("Tidak ada antrian\n");
  }
  else
  {
    while (curr != NULL && strcmp(curr->nama, nama) != 0)
    {
      curr = curr->next;
    }
    if (curr == NULL)
    {
      printf("Nama tidak ada\n");
      system("pause");
    }
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


// Print with FIFO (First In First Out)
void fifoPrint(Node *head)
{
  Node *curr = head;
  int count = 0;
  if(curr == NULL){
    printf("Tidak ada antrian\n");
  }
  else{
    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    while (curr != NULL)
    {
      count++;
      printf("[%d] nama : %s \n", count, curr->nama);
      curr = curr->prev;
    }
  }
}

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
}

