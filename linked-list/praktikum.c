#include <stdio.h>
#include <stdlib.h>

typedef struct node *address;

typedef struct node
{
  int data;
  address next;
} Node;

address createNode(int data)
{
  address newNode = (address)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

address insertFirst(address head, int val)
{
  address newNode = createNode(val);
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    newNode->next = head;

    head = newNode;
  }
  return (head);
}

address insertLast(address head, int val)
{
  address newNode = createNode(val);
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    address tail = head;
    while (tail->next != NULL)
    {
      tail = tail->next;
    }
    tail->next = newNode;
  }
  return (head);
}

address insertAfter(address head, int val, int prev_val)
{
  address newNode = createNode(val);
  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    address temp = head;
    while (temp->data != prev_val)
    {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return (head);
  }
}

address insertBefore(address head, int val, int next_val)
{
  address newNode = createNode(val);
  if (head->data == next_val)
  {
    head = insertFirst(head, val);
  }
  else
  {
    address temp, prev;
    temp = head;
    do
    {
      prev = temp;
      temp = temp->next;
    } while (temp->data != next_val);
    newNode->next = temp;
    prev->next = newNode;
  }

  return (head);
}

address deleteFirst(address head)
{
  if (head == NULL)
  {
    return NULL;
  }
  else
  {
    address first = head;
    head = head->next;
    first->next = NULL;
    free(first);
    return (head);
  }
}

address deleteLast(address head)
{
  if (head == NULL)
  {
    return NULL;
  }
  else
  {
    address tail = head;
    address prevTail = NULL;
    while (tail->next != NULL)
    {
      prevTail = tail;
      tail = tail->next;
    }
    prevTail->next = NULL;
    free(tail);
    return (head);
  }
}

address deleteAfter(address head, int val)
{
  address temp = head;
  while (temp != NULL)
  {
    if (temp->data == val)
    {
      break;
    }
    temp = temp->next;
  }
  if (temp == NULL)
  {
    return NULL;
  }
  else
  {
    address after = temp->next;
    temp->next = after->next;
    after->next = NULL;
    free(after);
  }
  return (head);
}

void printList(address head)
{
  address temp = head;
  while (temp != NULL)
  {
    printf("[%d]->", temp->data);
    temp = temp->next;
  }
}

address count(address head)
{
  address temp = head;
  int count = 0;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  printf("Jumlah node: %d\n", count);
}

address dispose(address head)
{
  address temp = head;
  while (temp != NULL)
  {
    head = deleteFirst(head);
    temp = temp->next;
  }
  return (head);
}

int main()
{
  int pilih, val, val1;
  address head = NULL;
  while (1)
  {
    system("cls");
    printList(head);
    printf("\n======================== SINGLE LINKED LIST ========================\n");
    printf("1. Insert First\n");
    printf("2. Insert Last\n");
    printf("3. Insert After\n");
    printf("4. Insert Before\n");
    printf("5. Delete First\n");
    printf("6. Delete Last\n");
    printf("7. Delete After\n");
    printf("8. Hitung Jumlah Node\n");
    printf("9. Hapus Keseluruhan Node\n");
    printf("10. Keluar\n");
    printf("Pilihan Anda = ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
    {
      printf("Masukkan nilai = ");
      scanf("%d", &val);
      head = insertFirst(head, val);
      system("cls");
      break;
    }
    case 2:
    {
      printf("Masukkan nilai = ");
      scanf("%d", &val);
      head = insertLast(head, val);
      system("cls");
      break;
    }
    case 3:
    {
      printf("Masukkan nilai = ");
      scanf("%d", &val);
      printf("Masukkan nilai tersebut setelah = ");
      scanf("%d", &val1);
      head = insertAfter(head, val, val1);
      system("cls");
      break;
    }
    case 4:
    {
      printf("Masukkan nilai = ");
      scanf("%d", &val);
      printf("Masukkan nilai tersebut sebelum = ");
      scanf("%d", &val1);
      head = insertBefore(head, val, val1);
      system("cls");
      break;
    }
    case 5:
    {
      head = deleteFirst(head);
      system("cls");
      break;
    }
    case 6:
    {
      head = deleteLast(head);
      system("cls");
      break;
    }
    case 7:
    {
      printf("Masukkan nilai yang ingin dihapus = ");
      scanf("%d", &val);
      head = deleteAfter(head, val);
      system("cls");
      break;
    }
    case 8:
    {
      head = count(head);
      system("Pause");
      break;
    }
    case 9:
    {
      head = dispose(head);
      system("Pause");
      break;
    }
    case 10:
    {
      exit(1);
    }
    default:
    {
      printf("Pilihan tersebut tidak ada");
      break;
    }
    }
  }
  return 0;
}
