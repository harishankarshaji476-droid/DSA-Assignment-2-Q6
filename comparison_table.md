# Comparison Table

| Operation | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space | O(V²) | O(V + E) |
| BFS | O(V²) | O(V + E) |
| DFS | O(V²) | O(V + E) |
| Edge checking | O(1) | O(degree(v)) |
| Vertex-label search | O(V) | O(V) |
| Best use | Dense graphs | Sparse graphs |

For this graph, V = 6 and E = 6. The graph is sparse relative to the V² storage of a matrix.
