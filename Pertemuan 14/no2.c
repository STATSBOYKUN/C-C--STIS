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
        int weight = edges[i].weight;

        // buat node baru dari src ke dest
        ptrNode newNode = (ptrNode)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->weight = weight;

        // point node baru ke head
        newNode->next = graph->head[src];

        // point head ke node baru
        graph->head[src] = newNode;

        //Tambahkan ini untuk undirected
        //Undirected Graph selalu 2 arah sehingga kalau dalam bentuk matriks mereka bakal simetris

        // buat node baru dari dest ke src
        newNode = (ptrNode)malloc(sizeof(struct Node));
        newNode->dest = src;
        newNode->weight = weight;

        // point node baru ke head
        newNode->next = graph->head[dest];

        // point head ke node baru
        graph->head[dest] = newNode;
    }

    return graph;
}
