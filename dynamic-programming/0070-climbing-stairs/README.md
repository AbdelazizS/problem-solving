# Climbing Stairs

| Field      | Value     |
|------------|-----------|
| Pattern    | Dynamic Programming, 1D |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#70](https://leetcode.com/problems/climbing-stairs/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

You're climbing a staircase of `n` steps, taking either 1 or 2 steps at a time. Return the number of distinct ways to reach the top.

## Key Insight

To reach step `n`, the last move was either a 1-step from step `n-1` or a 2-step from step `n-2`. Every distinct way to reach `n-1` combined with a final 1-step, plus every distinct way to reach `n-2` combined with a final 2-step, covers all ways to reach `n` with no overlap — so `ways(n) = ways(n-1) + ways(n-2)`. This is the Fibonacci recurrence.

## Approach

1. Base cases: `ways(1) = 1`, `ways(2) = 2`.
2. Build up iteratively from step 3 to `n`, at each step summing the two previous results.
3. Keep only the last two values (`prev1`, `prev2`) instead of a full array, since the transition only ever looks back two steps.

## Edge Cases

- `n == 1` → 1 way.
- `n == 2` → 2 ways (1+1, or 2).
- The recurrence is identical to Fibonacci — recognizing that mapping is the main insight of this problem.
- O(1) space is achievable because the full `dp` table is never needed, only the last two entries.
