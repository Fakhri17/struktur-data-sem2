#include <stdio.h>
#include <stdlib.h>

struct set
{
  int key;
  int data;
};
struct set *array;
int capacity = 10;
int size = 0;

int hashFunction(int key)
{
  return (key % capacity);
}
int isPrime(int a)
{
  int i;
  if (a == 1 || a == 0)
  {
    return 0;
  }
  for (i = 2; i < a / 2; i++)
  {
    if (a % i == 0)
    {
      return 0;
    }
  }
  return 1;
}
int findPrime(int a)
{
  if (a % 2 == 0)
  {
    a++;
  }
  while (!isPrime(a))
  {
    a += 2;
  }
  return a;
}
void initializeArray()
{
  capacity = findPrime(capacity);
  array = (struct set *)malloc(capacity * sizeof(struct set));
  for (int i = 0; i < capacity; i++)
  {
    array[i].key = 0;
    array[i].data = 0;
  }
}

void add(int key, int data)
{
  int index = hashFunction(key);
  while (array[index].data != 0 && array[index].key != key)
  {
    index++;
  }
  array[index].data = data;
}


void deleteElement(int key)
{
  int index = hashFunction(key);
  if (array[index].data == 0)
  {
    printf("\n This key does not exist \n");
  }
  else
  {
    array[index].key = 0;
    array[index].data = 0;
    size--;
    printf("\n Key (%d) has been removed \n", key);
  }
}
void show()
{
  int i;
  for (i = 0; i < capacity; i++)
  {
    if (array[i].data == 0)
    {
      printf("\n array[%d]:  ", i);
    }
    else
    {
      printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].data);
    }
  }
}

int hashtableSize()
{
  return size;
}

int main()
{
  int choice, key, data, a;
  int c = 0;
  initializeArray();
  printf("capacity %d\n", capacity);
  do
  {
    show();
    printf("\n");
    a = hashtableSize();
    printf("Size of Hash Table is-:%d\n", a);

    printf("\n");
    printf("1.Insert item in the Hash Table"
           "\n2.Remove item from the Hash Table"
           "\n\n Please enter your choice: ");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\n");
      printf("Enter key -:\t");
      scanf("%d", &key);
      printf("Enter data -:\t");
      scanf("%d", &data);
      add(key, data);

      break;

    case 2:

      printf("Enter the key to delete-:");
      scanf("%d", &key);
      deleteElement(key);

      break;

    default:

      printf("Invalid Input\n");
    }

    printf("\nDo you want to continue (press 1 for yes): ");
    scanf("%d", &c);

  } while (c == 1);
}