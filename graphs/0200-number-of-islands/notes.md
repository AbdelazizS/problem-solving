# Number of Islands

Difficulty:
Medium

Date:
2026-08-21

Week:
3

Time Taken:
__ min

## Pattern

Graph, DFS, Connected Components

## Complexity

| Approach            | Time              | Space             |
|----------------------|-------------------|--------------------|
| DFS flood fill        | O(rows * cols)    | O(rows * cols) (recursion stack, worst case) |
| BFS flood fill        | O(rows * cols)    | O(min(rows, cols)) (queue) |

## Approach

1. Iterate over every cell of the grid.
2. On an unvisited land cell (`'1'`), that's a brand new island — increment the counter.
3. Flood-fill outward from that cell (DFS or BFS), marking every reachable land cell as visited so the outer loop skips the rest of that island.
4. Total increments at the end = total islands.

## Mistakes I Made

- Forgetting the bounds check in the recursive sink causes an array-index-out-of-bounds error.
- Forgetting to mark the starting cell visited before recursing can cause infinite recursion (revisiting the same cell back and forth).
- Treating diagonal neighbors as connected — only 4-directional adjacency counts here.

## What I Learned

- A grid is one of the most common implicit graph representations in interview problems — treat each cell as a node, adjacency = neighboring cells.
- "Count connected components" is the general shape of this problem; DFS/BFS flood fill from every unvisited node is the general technique, independent of whether the graph is a grid or an explicit adjacency list.
- Mutating the grid to mark visited cells avoids a separate visited set, but destroys the input — worth mentioning as a trade-off in an interview.

## Interview Takeaways

- Explicitly state the graph model: "each land cell is a node; it's connected to up/down/left/right land neighbors."
- Justify correctness: every land cell is visited exactly once total across all flood fills, so the count of flood-fill *starts* equals the number of connected components.
- Mention the BFS alternative if asked about recursion depth risk on very large grids (DFS could stack-overflow on a huge single island).

## Similar Problems

- Max Area of Island
- Number of Closed Islands
- Surrounded Regions
- Course Schedule (different graph shape, same BFS/DFS + visited-tracking idea)
