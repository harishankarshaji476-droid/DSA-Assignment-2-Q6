# Trace Tables

## BFS from A

| Step | Queue | Visited/Output |
|---|---|---|
| 1 | A | A |
| 2 | B, C | A, B, C |
| 3 | C, D, E | A, B, C |
| 4 | D, E, F | A, B, C, D |
| 5 | E, F | A, B, C, D, E |
| 6 | F | A, B, C, D, E, F |

**BFS result:** A → B → C → D → E → F

## DFS from A

| Step | Current vertex | Traversal |
|---|---|---|
| 1 | A | A |
| 2 | B | A, B |
| 3 | D | A, B, D |
| 4 | E | A, B, D, E |
| 5 | F | A, B, D, E, F |
| 6 | C | A, B, D, E, F, C |

**DFS result:** A → B → D → E → F → C

## Vertex Search

| Target | Matrix operations | List operations |
|---|---:|---:|
| A | 1 | 1 |
| E | 5 | 5 |
| F | 6 | 6 |
| Z | 6 | 6 |

## Edge Checking

| Edge | Matrix operations | List operations | Result |
|---|---:|---:|---|
| A-B | 1 | 1 | Connected |
| A-F | 1 | 2 | Not Connected |
| E-F | 1 | 2 | Connected |
| C-E | 1 | 2 | Not Connected |
