# Range Sum Query — Immutable

Difficulty:
Medium

Date:
2026-08-14

Week:
2

Time Taken:
__ min

## Pattern

Prefix Sum

## Complexity

| Approach                  | Build Time | Query Time | Space |
|---------------------------|------------|------------|-------|
| Sum every query directly  | O(1)       | O(n)       | O(1)  |
| Prefix sum                | O(n)       | O(1)       | O(n)  |

## Approach

1. Allocate a prefix-sum array with `nums.length + 1` positions.
2. Set `prefixSum[0]` to zero.
3. Store the running total through each position in the remaining entries.
4. For `sumRange(left, right)`, subtract the sum before `left` from the sum through `right`.

## Mistakes I Made

- A range ending at `right` needs `prefixSum[right + 1]` because prefix sums use exclusive end positions.
- Do not rebuild the sum for every query when the array never changes.

## What I Learned

- Prefix sums trade O(n) one-time preprocessing for O(1) range queries.
- Adding a leading zero eliminates the boundary case for queries that start at index `0`.

## Interview Takeaways

- Ask whether the array is immutable; updates require a different data structure.
- State both construction and query complexity.
- Explain the formula with a concrete range: `sumRange(1, 3) = prefixSum[4] - prefixSum[1]`.

## Similar Problems

- Range Sum Query 2D — Immutable
- Subarray Sum Equals K
- Product of Array Except Self
