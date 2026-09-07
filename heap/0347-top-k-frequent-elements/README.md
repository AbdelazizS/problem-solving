# Top K Frequent Elements

| Field      | Value     |
|------------|-----------|
| Pattern    | Hash Map + Heap, Top K |
| Difficulty | Medium    |
| Time       | O(n log k) |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#347](https://leetcode.com/problems/top-k-frequent-elements/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements, in any order.

## Key Insight

This is a two-stage problem: first reduce the array to "value → frequency" pairs (a counting problem, solved with a hash map), then find the `k` largest frequencies among those pairs (a Top-K problem, solved with a bounded min-heap) — exactly the same min-heap-capped-at-k technique as Kth Largest Element in an Array, just applied to frequency counts instead of raw values.

## Approach

1. Count every value's frequency into a hash map.
2. Push each (value, frequency) pair onto a min-heap ordered by frequency.
3. Whenever the heap exceeds size `k`, pop the lowest-frequency pair — the heap always holds the `k` highest-frequency pairs seen so far.
4. After processing all distinct values, drain the heap into the result (order doesn't matter per the problem statement).

## Edge Cases

- `k` equal to the number of distinct elements → every distinct value is returned.
- Ties in frequency → any valid subset of size `k` among the tied values is acceptable, since the problem allows any order/choice.
- All elements identical → a single entry with the full count, trivially the top (and only) frequent element.
- An O(n) bucket-sort alternative exists (bucket index = frequency, since frequency is bounded by array length) achieving true O(n) time instead of O(n log k) — worth mentioning as a further optimization.
