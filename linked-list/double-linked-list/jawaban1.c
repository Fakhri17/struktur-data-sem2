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


// print with FIFO (First In First Out)
void fifoPrint(Node *head)
{
  Node *curr = head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  while (curr != NULL)
  {
    printf("%d ", curr->data);
    curr = curr->prev;
  }
}


// print with LIFO (Last In First Out)
void lifoPrint(Node *head)
{
  Node *curr = head;
  while (curr != NULL)
  {
    printf("%d ", curr->data);
    curr = curr->next;
  }

}



int main(){
  Node *head = NULL;
  // INSERT DATA WITH WHILE LOOP
  // IF Y = continue input and N = stop input
  char choice;
  int data;

  do
  {
    printf("Masukkan Bilangan: ");
    scanf("%d", &data);
    head = insertFirst(head, data);
    printf("ada data lagi (y/t) ?  ");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');

  printf("\n");
  
  printf("Data bilangan telah di inputkan secara FIFO :\n");
  fifoPrint(head);
 
  printf("\n");

  printf("Data bilangan telah di inputkan secara LIFO :\n");
  lifoPrint(head);
  

  return 0;
}
