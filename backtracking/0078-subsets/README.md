# Subsets

| Field      | Value     |
|------------|-----------|
| Pattern    | Backtracking, Include/Exclude |
| Difficulty | Medium    |
| Time       | O(n &times; 2^n) |
| Space      | O(n) auxiliary (excluding output) |
| Status     | Solved    |
| LeetCode   | [#78](https://leetcode.com/problems/subsets/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an array of unique integers, return all possible subsets (the power set), with no duplicate subsets.

## Key Insight

Every subset is a distinct choice, for each element, of "include it or don't." Backtracking explores this decision tree explicitly: at each recursive call, record the current partial subset as one valid answer, then try extending it with each remaining candidate, undoing the choice after recursing (so the next candidate at that level starts clean).

## Approach

1. Recurse with a `start` index and a `current` partial subset.
2. On entry to the recursive call, immediately record `current` as a complete subset — every prefix built along the way is itself a valid subset.
3. Loop `i` from `start` to the end: add `nums[i]` to `current`, recurse with `start = i + 1` (never reuse an earlier index, which avoids duplicate subsets and permutation-order duplicates), then remove `nums[i]` (backtrack) before trying the next `i`.
4. Base case is implicit: when `start` reaches the array length, the loop simply doesn't execute and the call returns.

## Edge Cases

- Empty input array → only the empty subset `[[]]`.
- Single element → `[[], [x]]`.
- The empty subset and the full array itself are both included.
- No duplicate subsets are produced because `i + 1` (not `i`) is always used as the next start index.
