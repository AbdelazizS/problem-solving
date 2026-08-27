# Maximum Depth of Binary Tree

Difficulty:
Easy

Date:
2026-08-21

Week:
4

Time Taken:
__ min

## Pattern

Tree, DFS (Post-order)

## Complexity

| Approach                     | Time | Space |
|-------------------------------|------|-------|
| Recursive DFS                 | O(n) | O(h)  |
| Iterative BFS (level count)   | O(n) | O(n)  |

## Approach

1. If the current node is null, its depth is 0 (base case).
2. Recurse into the left and right children.
3. Combine: current depth = 1 + max(left depth, right depth).

## Mistakes I Made

- Forgetting the base case returns 0 (not 1) — an empty subtree contributes no depth.
- Conflating "depth" (number of nodes on the path) with "edges on the path" (which would be depth - 1).

## What I Learned

- Many tree problems reduce to "combine the result of the left subtree and the result of the right subtree" — this is a post-order pattern: process children first, then the parent.
- Space complexity for recursive tree DFS is O(h), the height, not O(n) — only worth noting O(n) in the worst case of a completely skewed (linked-list-like) tree.

## Interview Takeaways

- State the recursive definition explicitly before coding: depth(node) = 0 if null, else 1 + max(depth(left), depth(right)).
- Mention the iterative BFS alternative (level-order traversal, counting levels) as a way to avoid recursion stack depth in pathological (very unbalanced) trees.
- Distinguish this cleanly from Minimum Depth of Binary Tree, which has a subtlety around one-sided subtrees.

## Similar Problems

- Minimum Depth of Binary Tree
- Balanced Binary Tree
- Diameter of Binary Tree
- Binary Tree Level Order Traversal
