# Complexity Analysis

Let V be the number of vertices and E the number of edges.

- **Adjacency Matrix space:** O(V²)
- **Adjacency List space:** O(V + E)
- **BFS with matrix:** O(V²), because each visited vertex scans all V possible neighbours.
- **BFS with list:** O(V + E), because only stored edges are traversed.
- **DFS with matrix:** O(V²)
- **DFS with list:** O(V + E)
- **Edge existence check:** O(1) with a matrix; O(degree(v)) with a list after the endpoint labels are located.
- **Vertex-label search:** O(V) in both representations when labels are stored in an unsorted array/list.

For V = 6 and E = 6, the adjacency list avoids the V² matrix storage and is the more appropriate representation for a sparse social network.
