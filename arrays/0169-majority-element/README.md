# Majority Element

| Field      | Value     |
|------------|-----------|
| Pattern    | Boyer-Moore Voting |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#169](https://leetcode.com/problems/majority-element/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an integer array with a guaranteed majority element, return the value that appears more than `n / 2` times.

## Key Insight

The Boyer-Moore Voting algorithm cancels different values in pairs. Because the majority element appears more than all other values combined, it remains as the final candidate.
