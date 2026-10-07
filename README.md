# DSA Assignment 2 – Question 6

## Subject
PCCST303 – Data Structures and Algorithms

## Question 6
Consider a small social network with connections:
A–B, A–C, B–D, B–E, C–F, E–F.

### Contents
- `q6.c` – C implementation of adjacency matrix, adjacency list, BFS, DFS, vertex search and edge checking.
- `input.txt` – input data used for the execution.
- `trace_table.md` – BFS/DFS and operation trace tables.
- `comparison_table.md` – representation comparison.
- `complexity_analysis.md` – time and space complexity.
- `conclusion.md` – final conclusion.

## Results

- BFS from A: **A → B → C → D → E → F**
- DFS from A: **A → B → D → E → F → C**
- Adjacency Matrix space: **O(V²)**
- Adjacency List space: **O(V + E)**
- BFS/DFS: **O(V²)** with matrix and **O(V + E)** with list.
- Edge checking: **O(1)** with matrix and **O(degree(v))** with list.
- Vertex-label search: **O(V)** for both representations.

## Conclusion
For this sparse social network, the adjacency list is the more suitable representation because it uses less space and traversal examines only existing edges.
