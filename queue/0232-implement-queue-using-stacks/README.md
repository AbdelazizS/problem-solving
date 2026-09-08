# Implement Queue using Stacks

| Field      | Value     |
|------------|-----------|
| Pattern    | Queue, Two-Stack Simulation |
| Difficulty | Easy      |
| Time       | O(1) amortized per operation |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#232](https://leetcode.com/problems/implement-queue-using-stacks/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Implement a FIFO queue using only two stacks (LIFO), supporting `push`, `pop`, `peek`, and `empty`.

## Key Insight

Reversing a stack's contents onto a second stack flips their order — so an `inStack` (newest on top, oldest at bottom) transferred entirely onto an `outStack` comes out oldest-first, exactly the order a queue needs. Only transferring when `outStack` is empty (not on every operation) is what keeps this efficient: each element is moved from `inStack` to `outStack` at most once over its lifetime.

## Approach

1. `push(x)`: always just push onto `inStack` — O(1), no reordering needed yet.
2. `pop()` / `peek()`: if `outStack` is empty, pour all of `inStack` onto `outStack` (reversing order); then operate on `outStack`'s top, which is the oldest remaining element.
3. `empty()`: true only when both stacks are empty.
4. The transfer is lazy — it only happens when `outStack` runs dry, not on every single `pop`/`peek` call.

## Edge Cases

- Interleaved pushes and pops → correctly maintains FIFO order across the two-stack transfer boundary, since `outStack` is only refilled once fully drained.
- `pop()`/`peek()` on an empty queue is undefined behavior per the problem (guaranteed not to happen in valid test cases), so no explicit empty-check is required inside those methods.
- Amortized O(1): although a single call to `pop()` *can* cost O(n) (a full transfer), each element only ever gets moved from `inStack` to `outStack` once, so the total cost across n operations stays O(n), i.e. O(1) amortized per call.
