# Stack

## When to Use

- Matching brackets / nested structures
- Monotonic stack (next greater/smaller element)
- DFS simulation
- Undo/reverse operations

## Template

```java
Deque<Integer> stack = new ArrayDeque<>();
for (int num : nums) {
    while (!stack.isEmpty() && /* condition */) {
        stack.pop();
    }
    stack.push(num);
}
```

## Common Problems

- Valid Parentheses
- Daily Temperatures
- Largest Rectangle in Histogram
- Evaluate Reverse Polish Notation
