# Contains Duplicate II

| Field      | Value     |
|------------|-----------|
| Pattern    | Hash Map, Index Tracking |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(min(n, k)) |
| Status     | Solved    |
| LeetCode   | [#219](https://leetcode.com/problems/contains-duplicate-ii/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an integer array `nums` and an integer `k`, return true if there are two distinct indices `i` and `j` such that `nums[i] == nums[j]` and `abs(i - j) <= k`.

## Key Insight

Plain duplicate detection (Contains Duplicate I) only needs a hash set. Here the *distance* between duplicate occurrences also matters, so the hash map must store more than membership — it stores the most recent index each value was seen at, so on a repeat we can check the gap directly.

## Approach

1. Maintain a hash map from value to its most recently seen index.
2. For each index `i`, look up `nums[i]` in the map.
3. If it exists and `i - previousIndex <= k`, return true immediately.
4. Otherwise (or after the check), update the map with the current index — always keeping the *most recent* occurrence, since that gives the best (smallest) chance of satisfying the distance constraint on the next repeat.

## Edge Cases

- `k == 0` → only exact same index can match, which is impossible for distinct indices, so effectively always false.
- Duplicate values far apart (distance > k) must not count.
- Multiple repeats of the same value: always compare against the *most recent* prior index, not the first occurrence, since that maximizes the chance of being within `k`.
- Empty array or `k` larger than the whole array both handled naturally without special-casing.
