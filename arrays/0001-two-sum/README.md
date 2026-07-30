# Two Sum

| Field      | Value     |
|------------|-----------|
| Pattern    | Hash Map  |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#1](https://leetcode.com/problems/two-sum/) |

## Summary

Given an array of integers and a target, return indices of two numbers that add up to the target.

## Key Insight

For each number `x`, the complement `target - x` must have been seen earlier. A hash map tracks value → index as we scan left to right.
