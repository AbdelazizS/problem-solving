# House Robber

Difficulty:
Medium

Date:
2026-09-07

Week:
6

Time Taken:
__ min

## Pattern

Dynamic Programming, 1D (Non-Adjacent Selection)

## Complexity

| Approach                                   | Time | Space |
|-----------------------------------------------|------|-------|
| Brute-force recursion (no memo)                  | O(2^n) | O(n) call stack |
| Top-down memoization / bottom-up full array         | O(n) | O(n)  |
| Bottom-up, rolling variables                        | O(n) | O(1)  |

## Approach

1. `prev2` represents the best total achievable up through two houses back; `prev1` through one house back.
2. At each house, decide: skip it (`prev1`) or rob it (`prev2 + nums[i]`) — take the max.
3. Shift the window forward: what was `prev1` becomes `prev2`, and the new decision becomes the new `prev1`.
4. After the last house, `prev1` holds the answer.

## Mistakes I Made

- Initially trying to track "robbed the last house" as a boolean flag instead of two running totals — this gets complicated fast; the two-variable DP recurrence handles it more cleanly without explicit state flags.
- Forgetting that `dp[i-2]` needs to start at 0 for the first two houses (not undefined/error) — initializing both rolling variables to 0 handles the boundary automatically.

## What I Learned

- This is the template for "maximum score picking non-adjacent elements from a line" — the recurrence `dp[i] = max(dp[i-1], dp[i-2] + value[i])` shows up again in House Robber II (circular version) and Delete and Earn.
- Like Climbing Stairs, the recurrence only reaches back a constant number of steps, so O(1) space is achievable by rolling two variables instead of keeping a full array.

## Interview Takeaways

- State the two-choice framing explicitly at each house: rob or skip, and why "rob" must jump back two positions (adjacency constraint), not one.
- Compare directly to Climbing Stairs when asked: same rolling-variable DP shape, different recurrence (`+` vs `max` at the combination step).
- Mention House Robber II (houses arranged in a circle) as the natural follow-up, solved by running this same algorithm twice (excluding the first house, then excluding the last) and taking the max.

## Similar Problems

- House Robber II
- Delete and Earn
- Climbing Stairs
- Maximum Sum of Non-Adjacent Elements
