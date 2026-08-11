# Maximum Average Subarray I

| Field      | Value     |
|------------|-----------|
| Pattern    | Fixed-Size Sliding Window |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#643](https://leetcode.com/problems/maximum-average-subarray-i/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an integer array and a window size `k`, find the maximum average of any contiguous subarray containing exactly `k` elements.

## Key Insight

For a fixed window size, maximize the window sum instead of repeatedly calculating each average. Slide the window by adding the new value and removing the value that leaves it.

## Approach

1. Calculate the sum of the first `k` values.
2. Slide the window one position at a time.
3. Add the entering value and subtract the leaving value.
4. Track the largest window sum, then divide it by `k` once.

## Edge Cases

- When `k` equals the array length, there is only one valid window.
- Negative values are handled naturally because the algorithm compares every valid window sum.
