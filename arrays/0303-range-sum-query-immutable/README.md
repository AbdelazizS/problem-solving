# Range Sum Query — Immutable

| Field      | Value     |
|------------|-----------|
| Pattern    | Prefix Sum |
| Difficulty | Medium    |
| Build Time | O(n)      |
| Query Time | O(1)      |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#303](https://leetcode.com/problems/range-sum-query-immutable/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Design a data structure that returns the sum of an immutable array between two inclusive indices, `left` and `right`.

## Key Insight

Repeatedly summing every value in a requested range repeats work. A prefix-sum array stores the sum before every index, so each query becomes one subtraction.

## Approach

1. Build `prefixSum` with one extra leading zero.
2. Let `prefixSum[i]` represent the sum of the first `i` values.
3. Answer an inclusive range with `prefixSum[right + 1] - prefixSum[left]`.

## Edge Cases

- A query can cover the whole array.
- A one-element query has `left == right`.
- The leading zero makes a query beginning at index `0` work without a special case.
