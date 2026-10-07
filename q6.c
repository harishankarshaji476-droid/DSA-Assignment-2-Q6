#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 6

const char labels[V] = {'A','B','C','D','E','F'};

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

void buildList(int graph[V][V], int adj[V][V], int degree[V]) {
    for (int i = 0; i < V; i++) degree[i] = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) adj[i][degree[i]++] = j;
        }
    }
}

void printList(int adj[V][V], int degree[V]) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < V; i++) {
        printf("%c -> ", labels[i]);
        for (int j = 0; j < degree[i]; j++) {
            printf("%c", labels[adj[i][j]]);
            if (j < degree[i] - 1) printf(" -> ");
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

void bfsList(int adj[V][V], int degree[V], int start) {
    int visited[V] = {0}, queue[V], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS using Adjacency List: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%c ", labels[u]);
        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i];
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

void dfsListUtil(int adj[V][V], int degree[V], int u, int visited[V]) {
    visited[u] = 1;
    printf("%c ", labels[u]);
    for (int i = 0; i < degree[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) dfsListUtil(adj, degree, v, visited);
    }
}

int searchMatrix(int graph[V][V], char target, int *operations) {
    *operations = 0;
    for (int i = 0; i < V; i++) {
        (*operations)++;
        if (labels[i] == target) return i;
    }
    return -1;
}

int searchList(int adj[V][V], int degree[V], char target, int *operations) {
    *operations = 0;
    for (int i = 0; i < V; i++) {
        (*operations)++;
        if (labels[i] == target) return i;
    }
    (void)adj; (void)degree;
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

int edgeCheckList(int adj[V][V], int degree[V], char a, char b, int *operations) {
    *operations = 0;
    int u = -1, v = -1;
    for (int i = 0; i < V; i++) {
        if (labels[i] == a) u = i;
        if (labels[i] == b) v = i;
    }
    if (u == -1 || v == -1) return 0;
    for (int i = 0; i < degree[u]; i++) {
        (*operations)++;
        if (adj[u][i] == v) return 1;
    }
    return 0;
}

int main(void) {
    int graph[V][V] = {0};
    int adj[V][V] = {0}, degree[V];
    buildMatrix(graph);
    buildList(graph, adj, degree);

    printMatrix(graph);
    printList(adj, degree);

    bfsMatrix(graph, 0);
    bfsList(adj, degree, 0);

    int visited[V] = {0};
    printf("\nDFS using Adjacency Matrix: ");
    dfsMatrixUtil(graph, 0, visited);
    printf("\n");

    for (int i = 0; i < V; i++) visited[i] = 0;
    printf("DFS using Adjacency List: ");
    dfsListUtil(adj, degree, 0, visited);
    printf("\n");

    char targets[] = {'A','E','F','Z'};
    printf("\nVertex Search Operations:\nTarget  Matrix  List\n");
    for (int i = 0; i < 4; i++) {
        int om, ol;
        int rm = searchMatrix(graph, targets[i], &om);
        int rl = searchList(adj, degree, targets[i], &ol);
        printf("%c       %d       %d\n", targets[i], om, ol);
        (void)rm; (void)rl;
    }

    char pairs[][2] = {{'A','B'},{'A','F'},{'E','F'},{'C','E'}};
    printf("\nEdge Checking Operations:\nEdge  Matrix  List  Result\n");
    for (int i = 0; i < 4; i++) {
        int om, ol;
        int rm = edgeCheckMatrix(graph, pairs[i][0], pairs[i][1], &om);
        int rl = edgeCheckList(adj, degree, pairs[i][0], pairs[i][1], &ol);
        printf("%c-%c     %d       %d      %s\n",
               pairs[i][0], pairs[i][1], om, ol, rm ? "Connected" : "Not Connected");
        (void)rl;
    }

    return 0;
}
