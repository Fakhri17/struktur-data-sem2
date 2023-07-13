#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// deklarasi struct Graph
// memiliki atribut edges (matriks adjacency) dan numVertices
typedef struct Graph{
  int edges[MAX_VERTICES][MAX_VERTICES];
  int numVertices;
} Graph;

// fungsi untuk menginisialisasi Graph
void initializeGraph(Graph *graph)
{
  graph->numVertices = 0;
  // lakukan iterasi untuk setiap elemen edges, set valuenya menjadi 0
  for (int i = 0; i < MAX_VERTICES; i++)
  {
    for (int j = 0; j < MAX_VERTICES; j++)
    {
      graph->edges[i][j] = 0;
    }
  }
}

// fungsi untuk menambahkan edge baru
void addEdge(Graph *graph, int source, int destination)
{
  // set edges[source][destination] menjadi 1
  // set edges[destination][source] menjadi 1
  graph->edges[source][destination] = 1;
  graph->edges[destination][source] = 1;
}

// fungsi untuk menghindari persimpangan yang memiliki lebih dari maxIntersection
void avoidIntersections(Graph *graph, int maxIntersection, int currentAge)
{
  printf("Persimpangan yang harus dihindari oleh Roronoa Zoro adalah:\n");
  // lakukan iterasi sebanyak numVertices
  for (int i = 0; i < graph->numVertices; i++)
  {
    int intersectionCount = 0;
    // lakukan iterasi sebanyak numVertices
    for (int j = 0; j < graph->numVertices; j++)
    {
      // jika edges[i][j] == 1, maka increment intersectionCount
      if (graph->edges[i][j] == 1)
      {
        intersectionCount++;
      }
    }
    // jika intersectionCount > maxIntersection, maka print i
    if (intersectionCount > maxIntersection)
    {
      printf("Persimpangan %d\n", i);
    }
  }
}

int main()
{
  Graph graph;
  int row, col, source, destination;
  
  scanf("%d", &row);
  scanf("%d", &col);
  initializeGraph(&graph);


  while (1)
  {
    scanf("%d %d", &source, &destination);
    // jika source == -1 dan destination == -1, maka perulangan berhenti
    if (source == -1 && destination == -1)
    {
      break;
    }
    addEdge(&graph, source, destination);
    graph.numVertices++;
  }

  avoidIntersections(&graph, col, col);

  return 0;
}
