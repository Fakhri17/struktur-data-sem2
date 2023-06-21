#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

Node *insertFirst(Node *head, int val)
{
  Node *newNode = createNode(val);
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

Node *insertLast(Node *head, int val)
{
  Node *newNode = createNode(val);
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    Node *tail = head;
    while (tail->next != NULL)
    {
      tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
  }
  return head;
}

Node *insertAfter(Node *head, int val, int prev_val)
{
  Node *newNode = createNode(val);
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    Node *temp = head;
    while (temp->data != prev_val)
    {
      temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
  }
  return head;
}

Node *insertBefore(Node *head, int val, int next_val)
{
  Node *newNode = createNode(val);
  if (head->data == next_val)
  {
    head = insertFirst(head, val);
  }
  else
  {
    Node *temp, *prev;
    temp = head;
    do
    {
      prev = temp;
      temp = temp->next;

    } while (temp->data != next_val);
    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = temp;
    temp->prev = newNode;
  }
  return head;
}

Node *deleteFirst(Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }
  else
  {
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
  }
  return head;
}

Node *deleteLast(Node *head)
{
  if (head == NULL)
  {
    return NULL;
  }
  else
  {
    Node *tail = head;
    while (tail->next != NULL)
    {
      tail = tail->next;
    }
    tail->prev->next = NULL;
    tail->prev = NULL;
    free(tail);
  }
  return head;
}

Node *deleteAfter(Node *head, int prev_val)
{
  Node *temp = head;

  while (temp != NULL)
  {
    if (temp->data == prev_val)
    {
      break;
    }
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL)
  {
    return head;
  }
  else
  {
    Node *del = temp->next;
    temp->next = del->next;

    if (del->next != NULL)
    {
      del->next->prev = temp;
    }

    del->next = NULL;
    del->prev = NULL;
    free(del);
  }

  return head;
}

void printList(Node *head)
{
  Node *curr = head;
  while (curr != NULL)
  {
    printf("[%d] ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

// count
Node *count(Node *head)
{
  int count = 0;
  Node *curr = head;
  while (curr != NULL)
  {
    count++;
    curr = curr->next;
  }
  printf("Jumlah node: %d\n", count);
  return (head);
}

Node *dispose(Node *head)
{
  while (head != NULL)
  {
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
  }
  printf("List sudah dikosongkan\n");
  return (head);
}

// search node
Node *searchNode(Node *head, int val)
{
  Node *curr = head;
  while (curr != NULL)
  {
    if (curr->data == val)
    {
      return curr;
    }
    curr = curr->next;
  }
}

int main()
{
  int pilihan, val, prev_val;
  Node *head = NULL;
  while (1)
  {
    system("cls");
    // printf("\n");
    printList(head);
    printf("1. Insert First\n");
    printf("2. Insert Last\n");
    printf("3. Insert After\n");
    printf("4. Insert Before\n");
    printf("5. Delete First\n");
    printf("6. Delete Last\n");
    printf("7. Delete After\n");
    printf("8. Count\n");
    printf("9. Dispose\n");
    printf("10. Search\n");
    printf("11. Exit\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
    {
      printf("Masukkan data: ");
      scanf("%d", &val);
      head = insertFirst(head, val);
      break;
    }
    case 2:
    {
      printf("Masukkan data: ");
      scanf("%d", &val);
      head = insertLast(head, val);
      break;
    }
    case 3:
    {
      printf("Masukkan data: ");
      scanf("%d", &val);
      printf("Masukkan data sebelumnya: ");
      scanf("%d", &prev_val);
      head = insertAfter(head, val, prev_val);
      break;
    }

    case 4:
    {
      printf("Masukkan data: ");
      scanf("%d", &val);
      printf("Masukkan data sesudahnya: ");
      scanf("%d", &prev_val);
      head = insertBefore(head, val, prev_val);
      break;
    }
    case 5:
    {
      head = deleteFirst(head);
      break;
    }

    case 6:
    {
      head = deleteLast(head);
      break;
    }
    case 7:
    {
      printf("Masukkan data sebelumnya: ");
      scanf("%d", &prev_val);
      head = deleteAfter(head, prev_val);
      break;
    }
    case 8:
    {
      head = count(head);
      system("pause");
      break;
    }
    case 9:
    {
      head = dispose(head);
      system("pause");
      break;
    }

    case 10:
    {
      int val;
      printf("Masukkan data yang ingin dicari: ");
      scanf("%d", &val);
      if (searchNode(head, val) != NULL)
      {
        printf("Data %d ditemukan\n", val);
      }
      else
      {
        printf("Data %d tidak ditemukan\n", val);
      }
      system("pause");
      break;
    }
    case 11:
    {
      printf("Terima kasih telah menggunakan program ini\n");
      printf("Tekan enter untuk keluar...");
      exit(0);
      break;
    }

    default:
    {
      printf("Pilihan tidak tersedia\n");
      break;
    }
    }
  }
}