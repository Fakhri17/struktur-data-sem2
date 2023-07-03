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

// membuat fungsi shuffleList untuk mengacak linked list
void shuffleList(Node **head, Node **tail)
{
  int count = 0;
  Node *current = *head;
  Node *temp = NULL;

  // Menghitung jumlah node
  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  srand(time(NULL));

  // Melakukan pengacakan
  for (int i = 0; i < count; i++)
  {
    int j = rand() % count;
    int k = rand() % count;
    Node *node1 = *head;
    Node *node2 = *head;
    int m = 0, n = 0;
    while (m < j)
    {
      node1 = node1->next;
      m++;
    }
    while (n < k)
    {
      node2 = node2->next;
      n++;
    }
    // Menukar nilai data antara dua node
    int tempData = node1->data;
    node1->data = node2->data;
    node2->data = tempData;
  }
}

int main()
{
  // Inisialisasi linked list
  Node *head = NULL;
  Node *tail = NULL;
  // Inisialisasi data
  int data[5] = {1, 2, 3, 4, 5};
  // Menambahkan node ke linked list
  for (int i = 0; i < 5; i++)
  {
    addNode(&head, &tail, data[i]);
  }

  // Mencetak linked list sebelum diacak
  printf("Sebelum diacak:\n");
  printList(head);

  // Mengacak linked list
  printf("\n");
  shuffleList(&head, &tail);

  // Mencetak linked list setelah diacak
  printf("Setelah diacak:\n");
  printList(head);

  return 0;
}
