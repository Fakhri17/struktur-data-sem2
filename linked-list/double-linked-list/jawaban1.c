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

// membuat fungsi print dengan skema FIFO 
void fifoPrint(Node *head)
{
  // membuat node variabel curr untuk menerima head
  Node *curr = head;
  // jika curr->next tidak sama dengan null maka curr = curr->next
  // untuk menemukan data yg pertama kali masuk
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  // jika curr !=null maka melakukan output
  while (curr != NULL)
  {
    printf("%d ", curr->data);
    curr = curr->prev;
  }
}

// membuat fungsi dengan skema LIFO
void lifoPrint(Node *head)
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

int main(){
  // deklarasi head node = NULL
  // membuat vairabel char choice untuk pemilihan
  // dan variabel int data untuk menampung data
  Node *head = NULL;
  char choice;
  int data;

  // melakukan looping secara terus menerusan untuk mendapatkan nilai
  // looping berhenti jika menekan huruf selain Y / menekan huruf T
  do
  {
    printf("Masukkan Bilangan: ");
    scanf("%d", &data);
    head = insertFirst(head, data);
    printf("ada data lagi (y/t) ?  ");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');
  printf("\n");

  // menampilkan dalam bentuk FIFO
  printf("Data bilangan telah di inputkan secara FIFO :\n");
  fifoPrint(head);
 
  printf("\n");
  // menampilkan dalam bentuk LIFO
  printf("Data bilangan telah di inputkan secara LIFO :\n");
  lifoPrint(head);
  
  return 0;
}
