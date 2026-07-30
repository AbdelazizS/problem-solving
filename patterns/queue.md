# Queue

## When to Use

- BFS level-order traversal
- Sliding window maximum (with deque)
- Task scheduling

## Template (BFS)

```java
Queue<TreeNode> queue = new ArrayDeque<>();
queue.offer(root);
while (!queue.isEmpty()) {
    int size = queue.size();
    for (int i = 0; i < size; i++) {
        TreeNode node = queue.poll();
        // process node
    }
}
```

## Common Problems

- Binary Tree Level Order Traversal
- Sliding Window Maximum
- Design Hit Counter
