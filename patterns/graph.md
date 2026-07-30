# Graph

## When to Use

- Relationships between entities
- Shortest path, connectivity, cycles

## Representations

- Adjacency list: `Map<Integer, List<Integer>>`
- Adjacency matrix for dense graphs

## Template (BFS)

```java
Set<Integer> visited = new HashSet<>();
Queue<Integer> queue = new ArrayDeque<>();
queue.offer(start);
visited.add(start);

while (!queue.isEmpty()) {
    int node = queue.poll();
    for (int neighbor : graph.get(node)) {
        if (!visited.contains(neighbor)) {
            visited.add(neighbor);
            queue.offer(neighbor);
        }
    }
}
```

## Common Problems

- Number of Islands
- Course Schedule
- Clone Graph
- Word Ladder
