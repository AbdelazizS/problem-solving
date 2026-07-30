# Java Collections Cheat Sheet

## List

```java
List<Integer> list = new ArrayList<>();
list.add(1);
list.get(0);
list.size();
```

## Set

```java
Set<Integer> set = new HashSet<>();       // O(1) add/contains
Set<Integer> treeSet = new TreeSet<>();    // sorted, O(log n)
```

## Map

```java
Map<String, Integer> map = new HashMap<>();
map.put("key", 1);
map.getOrDefault("key", 0);
map.containsKey("key");

// Frequency count
map.merge(num, 1, Integer::sum);
```

## Queue / Deque

```java
Queue<Integer> queue = new ArrayDeque<>();
queue.offer(1);
queue.poll();

Deque<Integer> deque = new ArrayDeque<>();
deque.offerFirst(1);
deque.offerLast(2);
```

## Priority Queue (Heap)

```java
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
```

## Arrays Utilities

```java
Arrays.sort(nums);
Arrays.fill(arr, 0);
Arrays.asList(1, 2, 3); // fixed-size list
```

## Useful Imports

```java
import java.util.*;
```

## Prefer `ArrayDeque` over `Stack` and `LinkedList` for stack/queue operations.
