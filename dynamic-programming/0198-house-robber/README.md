# House Robber

| Field      | Value     |
|------------|-----------|
| Pattern    | Dynamic Programming, 1D (Non-Adjacent Selection) |
| Difficulty | Medium    |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#198](https://leetcode.com/problems/house-robber/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an array of non-negative integers representing money in houses arranged in a line, find the maximum amount that can be robbed without robbing two adjacent houses.

## Key Insight

At each house, there are only two choices: rob it (and add its value to the best result *excluding* the previous house), or skip it (and keep the best result *including* the previous house). Tracking just those two running values — best-if-previous-house-was-skippable and best-two-houses-back — is enough to make the decision at every step without an explicit array.

## Approach

1. Define `dp[i]` = maximum amount robbable from the first `i` houses.
2. Transition: `dp[i] = max(dp[i-1], dp[i-2] + nums[i])` — either skip house `i` (inherit the best from `i-1`), or rob it (best from `i-2`, plus its value).
3. Base cases: `dp[-1] = 0` (no houses), `dp[-2] = 0` conceptually — realized here as `prev1 = prev2 = 0` before the loop starts.
4. Roll the last two values forward through the array instead of keeping a full table, since the recurrence only ever looks back two steps.

## Edge Cases

- Empty array → 0 (nothing to rob).
- Single house → rob it, return its value.
- Two houses → rob whichever is larger (can't take both, they're adjacent).
- All-zero values → 0, handled naturally without special-casing.
