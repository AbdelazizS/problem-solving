# Maximum Depth of Binary Tree

| Field      | Value     |
|------------|-----------|
| Pattern    | Tree, DFS (Post-order) |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(h)      |
| Status     | Solved    |
| LeetCode   | [#104](https://leetcode.com/problems/maximum-depth-of-binary-tree/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given the root of a binary tree, return its maximum depth — the number of nodes along the longest path from the root down to the farthest leaf.

## Key Insight

The depth of a tree rooted at `node` is `1 + max(depth of left subtree, depth of right subtree)`, with an empty tree having depth 0. This self-similar definition maps directly onto recursion.

## Approach

1. Base case: an empty node (`null`) has depth 0.
2. Recursively compute the depth of the left and right subtrees.
3. Return `1 +` the larger of the two (the `+1` accounts for the current node).

## Edge Cases

- Empty tree (`root == null`) → depth 0.
- Single node → depth 1.
- Skewed tree (every node has only one child) → depth equals the number of nodes.
- Space complexity is O(h) for the recursion stack, where `h` is tree height — O(n) worst case for a skewed tree, O(log n) for a balanced tree.
