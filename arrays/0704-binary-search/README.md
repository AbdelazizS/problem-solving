# Binary Search

| Field      | Value     |
|------------|-----------|
| Pattern    | Binary Search |
| Difficulty | Easy      |
| Time       | O(log n)  |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#704](https://leetcode.com/problems/binary-search/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given a sorted integer array and a target value, return the target's index or `-1` when it is absent.

## Key Insight

Because the array is sorted, comparing the middle value with the target tells us which half cannot contain the answer. Discard that half and repeat.

## Approach

1. Set inclusive `left` and `right` boundaries around the whole array.
2. Compare the middle value with `target`.
3. Discard the left or right half that cannot contain the target.
4. Return `-1` when the search range becomes empty.

## Edge Cases

- The target can be at either end of the array.
- An empty search range returns `-1`.
- The approach requires the input array to be sorted.
