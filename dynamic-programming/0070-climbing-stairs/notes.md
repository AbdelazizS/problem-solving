# Climbing Stairs

Difficulty:
Easy

Date:
2026-08-22

Week:
3

Time Taken:
__ min

## Pattern

Dynamic Programming, 1D

## Complexity

| Approach                          | Time       | Space |
|-------------------------------------|------------|-------|
| Naive recursion (no memo)            | O(2^n)     | O(n) call stack |
| Top-down memoization                 | O(n)       | O(n)  |
| Bottom-up tabulation (full array)    | O(n)       | O(n)  |
| Bottom-up, rolling variables         | O(n)       | O(1)  |

## Approach

1. Define `dp[i]` = number of distinct ways to reach step `i`.
2. Base cases: `dp[1] = 1`, `dp[2] = 2`.
3. Transition: `dp[i] = dp[i-1] + dp[i-2]` — the last move to reach `i` was either a 1-step or a 2-step.
4. Since the transition only depends on the last two values, collapse the array into two rolling variables.

## Mistakes I Made

- Starting with plain recursion without memoization first — exposes the exponential blowup (recomputing the same subproblems) before appreciating why DP is needed.
- Off-by-one on base cases: `dp[0]` (empty staircase) is technically 1 way (do nothing), but it's cleaner to start the base cases at `dp[1]` and `dp[2]` directly for this problem.

## What I Learned

- This is the canonical "count the number of ways" DP: identify the last decision (last step taken), and sum over the ways to reach each state that decision could have come from.
- Recognizing a Fibonacci-shaped recurrence is a common DP pattern signal — "current state = sum/combination of a fixed small window of previous states."
- Space optimization from O(n) to O(1) is possible whenever the recurrence only reaches back a constant number of steps — worth calling out explicitly as a follow-up optimization in an interview.

## Interview Takeaways

- State the recurrence and *why* it's correct: every path to step `n` ends in exactly one last move (1-step or 2-step), and those two cases are disjoint and exhaustive.
- Mention the Fibonacci connection immediately — it signals pattern recognition.
- Proactively bring up the O(1) space optimization instead of waiting to be asked.

## Similar Problems

- Fibonacci Number
- House Robber
- Min Cost Climbing Stairs
- Decode Ways
