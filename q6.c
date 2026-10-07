#include <stdio.h>
#include <stdlib.h>

#define V 6

const char labels[V] = {'A','B','C','D','E','F'};

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

void buildMatrix(int graph[V][V]) {
    int edges[][2] = {{0,1},{0,2},{1,3},{1,4},{2,5},{4,5}};
    int e = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < e; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }
}

void printMatrix(int graph[V][V]) {
    printf("Adjacency Matrix:\n  ");
    for (int i = 0; i < V; i++) printf("%c ", labels[i]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%c ", labels[i]);
        for (int j = 0; j < V; j++) printf("%d ", graph[i][j]);
        printf("\n");
    }
}

void addEdge(Node *adj[V], int u, int v) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = v;
    newNode->next = NULL;

    if (adj[u] == NULL) {
        adj[u] = newNode;
    } else {
        Node *current = adj[u];
        while (current->next != NULL) current = current->next;
        current->next = newNode;
    }
}

void buildList(Node *adj[V]) {
    int edges[][2] = {{0,1},{0,2},{1,3},{1,4},{2,5},{4,5}};
    int e = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < e; i++) {
        int u = edges[i][0], v = edges[i][1];
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }
}

void printList(Node *adj[V]) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < V; i++) {
        printf("%c -> ", labels[i]);
        Node *current = adj[i];
        while (current != NULL) {
            printf("%c", labels[current->vertex]);
            if (current->next != NULL) printf(" -> ");
            current = current->next;
        }
        printf("\n");
    }
}

void bfsMatrix(int graph[V][V], int start) {
    int visited[V] = {0}, queue[V], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS using Adjacency Matrix: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%c ", labels[u]);
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

void bfsList(Node *adj[V], int start) {
    int visited[V] = {0}, queue[V], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS using Adjacency List: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%c ", labels[u]);
        for (Node *current = adj[u]; current != NULL; current = current->next) {
            int v = current->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

void dfsMatrixUtil(int graph[V][V], int u, int visited[V]) {
    visited[u] = 1;
    printf("%c ", labels[u]);
    for (int v = 0; v < V; v++)
        if (graph[u][v] && !visited[v])
            dfsMatrixUtil(graph, v, visited);
}

void dfsListUtil(Node *adj[V], int u, int visited[V]) {
    visited[u] = 1;
    printf("%c ", labels[u]);
    for (Node *current = adj[u]; current != NULL; current = current->next) {
        int v = current->vertex;
        if (!visited[v]) dfsListUtil(adj, v, visited);
    }
}

int searchMatrix(char target, int *operations) {
    *operations = 0;
    for (int i = 0; i < V; i++) {
        (*operations)++;
        if (labels[i] == target) return i;
    }
    return -1;
}

int searchList(char target, int *operations) {
    *operations = 0;
    for (int i = 0; i < V; i++) {
        (*operations)++;
        if (labels[i] == target) return i;
    }
    return -1;
}

int edgeCheckMatrix(int graph[V][V], char a, char b, int *operations) {
    *operations = 1;
    int u = -1, v = -1;
    for (int i = 0; i < V; i++) {
        if (labels[i] == a) u = i;
        if (labels[i] == b) v = i;
    }
    if (u == -1 || v == -1) return 0;
    return graph[u][v];
}

int edgeCheckList(Node *adj[V], char a, char b, int *operations) {
    *operations = 0;
    int u = -1, v = -1;
    for (int i = 0; i < V; i++) {
        if (labels[i] == a) u = i;
        if (labels[i] == b) v = i;
    }
    if (u == -1 || v == -1) return 0;

    for (Node *current = adj[u]; current != NULL; current = current->next) {
        (*operations)++;
        if (current->vertex == v) return 1;
    }
    return 0;
}

void freeList(Node *adj[V]) {
    for (int i = 0; i < V; i++) {
        Node *current = adj[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}

int main(void) {
    int graph[V][V] = {0};
    Node *adj[V] = {NULL};

    buildMatrix(graph);
    buildList(adj);

    printMatrix(graph);
    printList(adj);

    bfsMatrix(graph, 0);
    bfsList(adj, 0);

    int visited[V] = {0};
    printf("\nDFS using Adjacency Matrix: ");
    dfsMatrixUtil(graph, 0, visited);
    printf("\n");

    for (int i = 0; i < V; i++) visited[i] = 0;
    printf("DFS using Adjacency List: ");
    dfsListUtil(adj, 0, visited);
    printf("\n");

    char targets[] = {'A','E','F','Z'};
    printf("\nVertex Search Operations:\nTarget  Matrix  List\n");
    for (int i = 0; i < 4; i++) {
        int om, ol;
        searchMatrix(targets[i], &om);
        searchList(targets[i], &ol);
        printf("%c       %d       %d\n", targets[i], om, ol);
    }

    char pairs[][2] = {{'A','B'},{'A','F'},{'E','F'},{'C','E'}};
    printf("\nEdge Checking Operations:\nEdge  Matrix  List  Result\n");
    for (int i = 0; i < 4; i++) {
        int om, ol;
        int rm = edgeCheckMatrix(graph, pairs[i][0], pairs[i][1], &om);
        edgeCheckList(adj, pairs[i][0], pairs[i][1], &ol);
        printf("%c-%c     %d       %d      %s\n",
               pairs[i][0], pairs[i][1], om, ol, rm ? "Connected" : "Not Connected");
    }

    freeList(adj);
    return 0;
}
