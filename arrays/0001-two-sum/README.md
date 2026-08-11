# Two Sum

| Field      | Value     |
|------------|-----------|
| Pattern    | Hash Map  |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#1](https://leetcode.com/problems/two-sum/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an array of integers and a target, return indices of two numbers that add up to the target.

## Key Insight

For each number `x`, the complement `target - x` must have been seen earlier. A hash map tracks value → index as we scan left to right.

## Approach

1. Scan the array from left to right.
2. Compute the complement needed to reach `target`.
3. Return the stored index and current index when that complement is already in the map.
4. Otherwise, store the current value and its index.

## Edge Cases

- Duplicate values can form the answer, so check the complement before storing the current value.
- Negative values and a negative target work without any special handling.
