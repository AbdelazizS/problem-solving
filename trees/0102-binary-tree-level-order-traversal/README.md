# Binary Tree Level Order Traversal

| Field      | Value     |
|------------|-----------|
| Pattern    | Tree, BFS (Level Order) |
| Difficulty | Medium    |
| Time       | O(n)      |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#102](https://leetcode.com/problems/binary-tree-level-order-traversal/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given the root of a binary tree, return the values of its nodes grouped level by level, from top to bottom (each level as its own list, left to right).

## Key Insight

A queue naturally processes nodes in the order they were discovered — which is exactly breadth-first order. The trick to grouping by level (rather than just getting one flat BFS order) is snapshotting the queue's size at the start of each round: that size tells you exactly how many nodes belong to the current level, before any of their children get enqueued.

## Approach

1. If the tree is empty, return an empty result.
2. Push the root onto a queue.
3. While the queue isn't empty: record its current size — that's exactly how many nodes are in this level.
4. Dequeue that many nodes, collecting their values into a `level` list and enqueueing each one's non-null children.
5. Append `level` to the result, then repeat for the next level.

## Edge Cases

- Empty tree (`root == null`) → empty result list.
- Single node → one level containing just that value.
- Skewed tree (each node has only one child) → every level has exactly one node.
- The `size` snapshot at the top of each iteration is what prevents children enqueued during this level from being mistakenly processed as part of the same level.
