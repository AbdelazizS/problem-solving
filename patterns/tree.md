# Tree

## When to Use

- Hierarchical data
- DFS (pre/in/post-order) or BFS (level-order)
- BST properties for O(log n) search

## Traversals

```java
// DFS
void dfs(TreeNode node) {
    if (node == null) return;
    dfs(node.left);
    dfs(node.right);
}

// BFS — see queue.md
```

## Common Problems

- Maximum Depth of Binary Tree
- Validate Binary Search Tree
- Lowest Common Ancestor
- Binary Tree Maximum Path Sum
