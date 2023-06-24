#include <stdio.h>
#include <stdlib.h>

// deklarasi struct node untuk menampung data daouble linked list
// dengan 3 variabel yaitu data, next, dan prev
typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} Node;

// membuat fungsi untuk membuat node baru dengan paramater data untuk mendapatkan nilai
Node *createNode(int data)
{
  // untuk newnode digunakan untuk membuat node
  // untuk variabel newnode->data untuk menampung nilai
  // prev dan next kita buat null
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Membuat fungsi insert first dengan paramater Node sama val untuk mendapatkan nilai
Node *insertFirst(Node *head, int val)
{
  // newnode untuk dengan fungsi createnode untuk membuat node
  Node *newNode = createNode(val);
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

// membuat fungsi print dengan skema stack LIFO
void stackPrint(Node *head)
{
  // membuat node variabel curr untuk menerima head
  Node *curr = head;
  // jika curr !=null maka melakukan output
  while (curr != NULL)
  {
    printf("%d ", curr->data);
    curr = curr->next;
  }
}

// membuat fungsi reverse stack dengan skema stack LIFO
void reverseStack(Node *head)
{
  // membuat node variabel curr untuk menerima head
  Node *curr = head;
  // jika curr->next tidak sama dengan null maka curr = curr->next dan melakukan perulangan
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  // jika curr !=null maka melakukan output secara terbalik
  while (curr != NULL)
  {
    printf("%d ", curr->data);
    curr = curr->prev;
  }
}

// membuat fungsi main program untuk menjalankan program
int main()
{
  Node *head = NULL;
  char choice;
  int val;

  do
  {
    printf("Masukkan Nilai: ");
    scanf("%d", &val);
    head = insertFirst(head, val);
    printf("Tambah nilai lagi (y/t) ?  ");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');

  printf("\n");
  printf("Stack sebelum di Reverse : ");
  stackPrint(head);
  printf("\n");
  printf("Stack setelah di Reverse : ");
  reverseStack(head);
  return 0;
}