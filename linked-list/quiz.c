#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct telp *address;

typedef struct telp
{
  char name[255];
  char phone[255];
  address next;
} Telp;

address createNode(char name[], char phone[])
{
  address newNode = (address)malloc(sizeof(Telp));
  strcpy(newNode->name, name);
  strcpy(newNode->phone, phone);
  newNode->next = NULL;
  return newNode;
}

address insertLast(address head, char name[], char phone[])
{
  address newNode = createNode(name, phone);
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
  printf("Contact %s added\n", name);
  return (head);
}

void searchPhone(address head, char name[])
{
  address curr = head;
  while (curr != NULL)
  {
    if (strcmp(curr->name, name) == 0)
    {
      printf("Nama: %s\n", curr->name);
      printf("Nomer: %s\n", curr->phone);
      return;
    }
    curr = curr->next;
  }
  printf("Not Found\n");
}

void printList(address head)
{
  if (head == NULL)
  {
    printf("No contact found\n");
  }
  else
  {
    address curr = head;
    printf("Contact list:\n");
    while (curr != NULL)
    {
      printf("Nama: %s\n", curr->name);
      printf("Nomer: %s\n", curr->phone);
      curr = curr->next;
    }
  }
}

int main(){
  int pilihan;
  char name[255];
  char phone[255];
  address head = NULL;

  while (1)
  {
    system("cls");
    printf("Menu : \n");
    printf("1. Tambah Kontak\n");
    printf("2. Cari Kontak\n");
    printf("3. Lihat Semua Kontak\n");
    printf("4. Keluar\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
      printf("Nama: ");
      scanf("%s", name);
      printf("Nomer: ");
      scanf("%s", phone);
      head = insertLast(head, name, phone);
      break;
    case 2:
      printf("Nama: ");
      scanf("%s", name);
      searchPhone(head, name);
      system("pause");
      break;
    case 3:
      printList(head);
      system("pause");
      break;
    case 4:
      printf("Terima kasih\n");
      exit(1);
    default:
      printf("Pilihan tidak tersedia\n");
      break;
    }
  }
  
}
