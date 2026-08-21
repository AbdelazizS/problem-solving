# Number of Islands

| Field      | Value     |
|------------|-----------|
| Pattern    | Graph, DFS, Connected Components |
| Difficulty | Medium    |
| Time       | O(rows &times; cols) |
| Space      | O(rows &times; cols) |
| Status     | Solved    |
| LeetCode   | [#200](https://leetcode.com/problems/number-of-islands/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an `m x n` grid of `'1'` (land) and `'0'` (water), count the number of islands, where an island is formed by connecting adjacent lands horizontally or vertically.

## Key Insight

The grid is an implicit graph: each land cell is a node, and each land cell is connected to its up/down/left/right land neighbors. Counting islands is counting connected components. Every time we find an unvisited land cell, it must belong to a new component, so we increment the count and flood-fill (DFS) to mark the entire component as visited so it's never counted again.

## Approach

1. Scan every cell in the grid.
2. When a `'1'` is found that hasn't been visited yet, increment the island count.
3. DFS (sink) from that cell: mark it visited (flip to `'0'`) and recurse into its 4 neighbors, stopping at out-of-bounds cells or cells that are already `'0'`.
4. Continue scanning; the sink ensures every cell in the same island is consumed before the outer scan reaches it again.

## Edge Cases

- Empty grid → 0 islands.
- All water → 0 islands.
- All land → 1 island.
- Diagonally adjacent land cells are NOT connected — only up/down/left/right count.
- Mutates the input grid in place to mark visited cells (acceptable trade-off for O(1) extra visited-tracking; could use a separate `visited` array if mutation isn't allowed).
