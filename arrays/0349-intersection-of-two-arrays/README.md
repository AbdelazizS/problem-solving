# Intersection of Two Arrays

| Field      | Value     |
|------------|-----------|
| Pattern    | Sorting, Two Pointers |
| Difficulty | Easy      |
| Time       | O(n log n + m log m) |
| Space      | O(log n + log m), excluding output |
| Status     | Solved    |
| LeetCode   | [#349](https://leetcode.com/problems/intersection-of-two-arrays/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given two integer arrays, return the distinct values that occur in both arrays in any order.

## Key Insight

Sorting makes equal values and ordering relationships visible. Two pointers can then scan both arrays together, advancing the pointer with the smaller value until a match is found.

## Approach

1. Sort both arrays.
2. Start one pointer at the beginning of each array.
3. Add a match only when it is different from the previous result.
4. Advance the pointer with the smaller value, or both pointers after a match.

## Edge Cases

- Duplicates must appear only once in the result.
- An empty array produces an empty intersection.
- The result order does not matter.
