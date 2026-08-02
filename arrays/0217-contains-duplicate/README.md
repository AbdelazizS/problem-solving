# Contains Duplicate

| Field      | Value     |
|------------|-----------|
| Pattern    | Hash Set  |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#217](https://leetcode.com/problems/contains-duplicate/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an integer array, return `true` when any value appears at least twice; otherwise, return `false`.

## Key Insight

Keep a hash set of values already seen. If inserting a value fails because it is already present, a duplicate exists.
