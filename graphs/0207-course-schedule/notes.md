# Course Schedule

Difficulty:
Medium

Date:
2026-09-07

Week:
6

Time Taken:
__ min

## Pattern

Graph, Topological Sort (Kahn's Algorithm)

## Complexity

| Approach                                     | Time      | Space     |
|-------------------------------------------------|-----------|-----------|
| Kahn's algorithm (BFS, in-degree)                 | O(V + E)  | O(V + E)  |
| DFS with 3-color cycle detection                  | O(V + E)  | O(V + E) (recursion stack) |

## Approach

1. Build the graph and compute in-degree for every node (course).
2. Start a queue with all in-degree-0 nodes — courses with no unmet prerequisites.
3. Process the queue: each dequeued course is "completed," so decrement in-degree for its dependents; any that reach 0 become newly available and get enqueued.
4. Count how many courses got processed this way. If it matches `numCourses`, a valid completion order exists (no cycle); otherwise some courses were permanently stuck waiting on each other.

## Mistakes I Made

- Getting the edge direction backwards — the prerequisite pair `[a, b]` means `b -> a` (b must come first), so the adjacency list should map `prereq -> dependents`, not the other way around.
- Forgetting to seed the queue with *all* zero-in-degree nodes up front (not just one) — missing initial nodes from disconnected parts of the graph causes an incorrect "cycle detected" result even when no cycle exists.

## What I Learned

- "Can all tasks be completed given dependency constraints" is the standard signal for topological sort; a cycle in the dependency graph is exactly what makes it impossible.
- Kahn's algorithm reframes cycle detection as a counting problem: if you can't process every node via the zero-in-degree peeling process, whatever's left over must be part of a cycle (each node in a cycle always has at least one unprocessed prerequisite, so its in-degree never reaches 0).
- This is the same technique needed for Course Schedule II (returning the actual order, not just feasibility) — the queue's dequeue order *is* a valid topological order.

## Interview Takeaways

- State the graph model explicitly: node = course, directed edge = "must be completed before."
- Explain why in-degree 0 means "ready to take now," and why processing in that order can never get stuck unless a cycle exists.
- Mention the DFS-based alternative (3-color: unvisited / in-progress / done, cycle = revisiting an in-progress node) as an equally valid approach, useful if asked to detect *which* courses are in a cycle.

## Similar Problems

- Course Schedule II
- Alien Dictionary
- Minimum Height Trees
- Sequence Reconstruction
