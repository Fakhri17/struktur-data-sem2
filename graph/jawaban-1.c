#include <stdio.h>
#include <stdlib.h>

// deklarasi struct Node
// memiliki atribut data dan next (pointer ke Node selanjutnya)
typedef struct Node
{
  int data;
  struct Node *next;
} Node;
// deklarasi struct Graph
// memiliki atribut numVertices dan adjacencyLists (array of Node)
typedef struct Graph
{
  int numVertices;
  Node **adjacencyLists;
} Graph;

// fungsi untuk membuat Node baru
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// fungsi untuk membuat Graph baru
Graph *createGraph(int vertices)
{
  // alokasi memori untuk Graph
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  // set atribut numVertices dgn value dari parameter
  graph->numVertices = vertices;
  // alokasi memori untuk adjacencyLists
  graph->adjacencyLists = (Node **)malloc(vertices * sizeof(Node *));
  // lakukan iterasi untuk setiap elemen adjacencyLists, set valuenya menjadi NULL
  for (int i = 0; i < vertices; i++){
    graph->adjacencyLists[i] = NULL;
  }
  // return graph
  return graph;
}

// fungsi untuk menambahkan edge baru
void addEdge(Graph *graph, int src, int dest)
{
  // buat Node baru dengan value dest
  Node *newNode = createNode(dest);
  // set next dari newNode menjadi adjacencyLists[src]
  newNode->next = graph->adjacencyLists[src];
  // set adjacencyLists[src] menjadi newNode
  graph->adjacencyLists[src] = newNode;
  // buat Node baru dengan value src
  newNode = createNode(src);
  // set next dari newNode menjadi adjacencyLists[dest]
  newNode->next = graph->adjacencyLists[dest];
  // set adjacencyLists[dest] menjadi newNode
  graph->adjacencyLists[dest] = newNode;
}

// fungsi untuk mengecek apakah ada wibu nolep
void isWibuNolep(Graph *graph, int numPeople, int n)
{
  // deklarasi variabel, wibuNolep adalah array yang menyimpan index dari wibu nolep
  // wibuCount adalah jumlah wibu nolep
  int i, count;
  int wibuNolep[numPeople];
  int wibuCount = 0;

  // lakukan iterasi untuk setiap elemen adjacencyLists
  for (i = 0; i < numPeople; i++)
  {
    // set count menjadi 0
    count = 0;
    // buat variabel temp yang menunjuk ke adjacencyLists[i]
    Node *temp = graph->adjacencyLists[i];
    // lakukan iterasi selama temp tidak NULL
    while (temp)
    {
      // increment count dan pindahkan temp ke next
      count++;
      temp = temp->next;
    }
    // jika count <= n, maka wibuNolep[wibuCount] = i dan increment wibuCount
    if (count <= n)
    {
      wibuNolep[wibuCount] = i;
      wibuCount++;
    }
  }
  // lakukan iterasi untuk setiap elemen wibuNolep
  for (i = 0; i < wibuCount; i++)
  {
    // jika wibuNolep[i] != 2, maka print "Vertex %d adalah wibu nolep"
    if (wibuNolep[i] != 2)
    {
      printf("Vertex %d adalah wibu nolep\n", wibuNolep[i]);
    }
  }
}

// fungsi main
int main()
{
  int numPeople, n, source, dest;
  scanf("%d %d", &numPeople, &n);

  Graph *graph = createGraph(numPeople);

  while (1)
  {
    scanf("%d %d", &source, &dest);
    // jika source dan dest bernilai -1, perulangan dihentikan
    if (source == -1 && dest == -1){
      break;
    }
    addEdge(graph, source, dest);
  }
  // panggil fungsi isWibuNolep
  isWibuNolep(graph, numPeople, n);

  return 0;
}
