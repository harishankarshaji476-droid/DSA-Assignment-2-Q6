# Final Conclusion

The social network contains six vertices and six undirected edges. Both adjacency matrix and adjacency list representations produce the same BFS and DFS traversal order from A.

The adjacency matrix provides constant-time edge checking and direct indexed access, but requires O(V²) space. The adjacency list stores only the existing connections and uses O(V + E) space. Its BFS and DFS operations also run in O(V + E).

Therefore, the **adjacency list is more suitable for this sparse social network** because it uses less storage and avoids scanning non-existent edges during traversal. The execution and trace results support this choice.
