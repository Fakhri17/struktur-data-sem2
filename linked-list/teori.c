// create simple program to implement linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

node *head = NULL;
node *one = NULL;
node *two = NULL;
node *three = NULL;

void print(node **head)
{
  node *temp = *head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  node *head = NULL;
  node *one = NULL;
  node *two = NULL;
  node *three = NULL;

  one = malloc(sizeof(node));
  two = malloc(sizeof(node));
  three = malloc(sizeof(node));

  one->data = 1;
  two->data = 2;
  three->data = 3;

  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;
  print(&head);
}
