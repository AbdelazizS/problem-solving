# Kth Largest Element in an Array

| Field      | Value     |
|------------|-----------|
| Pattern    | Heap, Top K |
| Difficulty | Medium    |
| Time       | O(n log k) |
| Space      | O(k)      |
| Status     | Solved    |
| LeetCode   | [#215](https://leetcode.com/problems/kth-largest-element-in-an-array/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an unsorted array `nums` and an integer `k`, return the `k`-th largest element (the `k`-th largest in sorted order, not the `k`-th distinct value).

## Key Insight

We don't need to fully sort the array or track every element seen so far — only the k largest matter, and among those, only the smallest one (the boundary) matters at each step. A min-heap capped at size k always holds exactly the k largest elements seen so far, with the current k-th largest sitting at the top.

## Approach

1. Push every number onto a min-heap.
2. Whenever the heap grows past size k, pop the smallest (the heap enforces this is always the current minimum).
3. After processing all numbers, the heap contains exactly the k largest elements, and its top is the smallest of those — i.e. the k-th largest overall.

## Edge Cases

- `k == 1` → equivalent to finding the maximum.
- `k == nums.length` → equivalent to finding the minimum.
- Duplicate values must be counted by position in sorted order, not deduplicated.
- Quickselect (partition-based) achieves average O(n) time if the heap's O(n log k) isn't tight enough, at the cost of worst-case O(n^2) and mutating the input array.
