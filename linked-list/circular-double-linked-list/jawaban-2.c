#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// membuat struct Node
typedef struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

// membyat fungsi createNode sebagai pembuat node baru
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// membuat fungsi addNode untuk menambah node baru atau data baru
void addNode(Node **head, Node **tail, int data)
{
  Node *newNode = createNode(data);
  // jika head bernilai NULL, maka head dan tail akan sama dengan newNode
  if (*head == NULL)
  {
    *head = newNode;
    *tail = newNode;
  }
  // jika head tidak bernilai NULL, maka tail akan menunjuk ke newNode
  else
  {
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
  }
}

// membuat fungsi printList untuk mencetak linked list
void printList(Node *head)
{
  Node *current = head;
  // jika head NULL, maka linked list kosong
  if (head == NULL)
  {
    printf("Linked list kosong.\n");
    return;
  }
  // jika tidak, maka akan mencetak linked list sesuai data yang ditunjuk oleh current
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// membuat fungsi reverseList untuk mereverse linked list
void reverseList(Node **head, Node **tail){
  Node *current = *head;
  Node *temp = NULL;

  // jika current tidak bernilai NULL, maka akan mereverse linked list
  // dengan menukar posisi prev dan next
  while (current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  // jika temp tidak bernilai NULL, maka tail dan head akan menunjuk ke temp->prev
  if (temp != NULL)
  {
    *tail = *head;
    *head = temp->prev;
  }
}


int main()
{
  // Inisialisasi linked list
  Node *head = NULL;
  Node *tail = NULL;
  // Inisialisasi data
  int data[5] = {10, 20, 30, 40, 50};
  // Menambahkan node ke linked list
  for (int i = 0; i < 5; i++)
  {
    addNode(&head, &tail, data[i]);
  }

  // Mencetak linked list sebelum di reverse
  printf("Sebelum di reverse:\n");
  printList(head);

  // Mereverse linked list
  printf("\n");
  reverseList(&head, &tail);

  // Mencetak linked list setelah di reverse
  printf("Setelah di reverse:\n");
  printList(head);

  return 0;
}
