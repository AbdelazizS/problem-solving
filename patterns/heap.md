# Heap (Priority Queue)

## When to Use

- Top K elements
- Merge K sorted lists
- Median from data stream
- Dijkstra's algorithm

## Template

```java
// Min-heap (default in Java PriorityQueue)
PriorityQueue<Integer> minHeap = new PriorityQueue<>();

// Max-heap
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
```

## Common Problems

- Kth Largest Element in an Array
- Merge k Sorted Lists
- Find Median from Data Stream
- Task Scheduler
