#include <stdio.h>
#include <stdlib.h>
#define N 6 // misal maksimum node adalah 6
// Struktur data untuk menyimpan adjacency list dari node pada graph 
struct Node
{
   int dest;
   struct Node *next;
};
typedef struct Node *ptrNode;
// Struktur data untuk menyimpan onjek graph
struct Graph
{
   // array pointer ke node untuk representasi adjacency list
   ptrNode head[N];
};

typedef struct Graph *ptrGraph;
// Struktur data untuk menyimpan edge graph
struct Edge
{
   int src, dest;
};

// Fungsi untuk membuat adjacency list dari edge tertentu
ptrGraph createGraph(struct Edge edges[], int n)
{
   // alokasi memori untuk menyimpan struktur data graph
   ptrGraph graph = (ptrGraph)malloc(sizeof(struct Graph));
   // inisialiasi semua pointer head ke null
   for (int i = 0; i < N; i++)
   {
      graph->head[i] = NULL;
   }
   // menambahkan edge satu demi satu
   for (int i = 0; i < n; i++)
   {
      // ambil source dan destination dari node
      int src = edges[i].src;
      int dest = edges[i].dest;
      // buat node baru dari src ke dest
      ptrNode newNode = (ptrNode)malloc(sizeof(struct Node));
      newNode->dest = dest;
      // point node baru ke head
      newNode->next = graph->head[src];
      // point head ke node baru
      graph->head[src] = newNode;
   }
   return graph;
}
// Fungsi print representasi adjacency list
void printGraph(ptrGraph graph)
{
   int i;
   for (i = 0; i < N; i++)
   {
      // print node dan semua yang terhubung
      ptrNode ptr = graph->head[i];
      while (ptr != NULL)
      {
         printf("(%d -> %d)\t", i, ptr->dest);
         ptr = ptr->next;
      }
      printf("\n");
   }
}
void main()
{
   // input array pasangan dari x ke y
   struct Edge edges[] = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}};
   // menghitung jumlah edge
   int n = sizeof(edges) / sizeof(edges[0]);
   // membuat graph
   ptrGraph graph = createGraph(edges, n);
   // print graph
   printGraph(graph);
}