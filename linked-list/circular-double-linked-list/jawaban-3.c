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
    printf("Elemen %d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// membuat funbgsi mengurutkan linked list secara ascending
void sortAscending(Node **head, Node **tail)
{
  Node *current = *head;
  Node *index = NULL;
  int temp;

  if (*head == NULL)
  {
    return;
  }
  else
  {
    // melakukan sorting secara ascending menggunakan bubble sort
    // jika current tidak bernilai NULL, maka akan melakukan sorting
    while (current != NULL)
    {
      // index akan menunjuk ke node setelah current
      index = current->next;
      // jika index tidak bernilai NULL, maka akan melakukan sorting
      while (index != NULL)
      {
        // jika data yang ditunjuk oleh current lebih besar dari data yang ditunjuk oleh index, maka akan ditukar
        if (current->data > index->data)
        {
          temp = current->data;
          current->data = index->data;
          index->data = temp;
        }
        index = index->next;
      }
      current = current->next;
    }
  }
}


int main()
{
  // Inisialisasi linked list
  Node *head = NULL;
  Node *tail = NULL;
  // Inisialisasi data
  int data[5] = {3, 1, 4, 2, 5};
  // Menambahkan node ke linked list
  for (int i = 0; i < 5; i++)
  {
    addNode(&head, &tail, data[i]);
  }

  // Mencetak linked list sebelum di reverse
  printf("List sebelum di urutkan: ");
  printList(head);

  // Mereverse linked list
  printf("\n");
  sortAscending(&head, &tail);

  // Mencetak linked list setelah di reverse
  printf("List setelah di urutkan: ");
  printList(head);

  return 0;
}
