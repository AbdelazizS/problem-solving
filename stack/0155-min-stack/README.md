# Min Stack

| Field      | Value     |
|------------|-----------|
| Pattern    | Stack, Auxiliary Min-Tracking |
| Difficulty | Medium    |
| Time       | O(1) for every operation |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#155](https://leetcode.com/problems/min-stack/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Design a stack that supports `push`, `pop`, `top`, and retrieving the minimum element (`getMin`) — all in O(1) time.

## Key Insight

A plain stack can't answer "what's the minimum?" without scanning everything. The trick is to maintain a second, parallel stack that records "what was the minimum at this depth" alongside every push — so popping the main stack automatically pops back to the correct previous minimum, with no scanning needed.

## Approach

1. Maintain two stacks: `stack` (actual values) and `minStack` (running minimum at each depth).
2. On `push(val)`: push `val` onto `stack`; push `min(val, minStack.peek())` onto `minStack` (or just `val` if `minStack` is empty).
3. On `pop()`: pop both stacks together, keeping them in lockstep.
4. `top()` returns `stack.peek()`; `getMin()` returns `minStack.peek()` — both O(1).

## Edge Cases

- Pushing a new minimum, then popping it — `minStack` correctly reverts to the prior minimum because each level remembers its own minimum, not just a single global variable.
- Pushing duplicate minimum values must still track correctly through multiple pops (this "always push" approach handles it trivially, since each duplicate gets its own `minStack` entry).
- The `minStack` approach here trades O(n) extra space for O(1) time and code simplicity, versus an optimized version that only pushes to `minStack` when a value is `<=` the current min (fewer pushes, same asymptotic space in the worst case).
