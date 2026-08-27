# Two Sum II - Input Array Is Sorted

| Field      | Value     |
|------------|-----------|
| Pattern    | Two Pointers, Opposite Ends (Sorted Search) |
| Difficulty | Medium    |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given a 1-indexed sorted array `numbers` and a `target`, return the 1-indexed positions of the two numbers that add up to `target`. Exactly one solution is guaranteed to exist, and the same element can't be used twice.

## Key Insight

Because the array is sorted, moving the left pointer right always increases the sum, and moving the right pointer left always decreases it. That monotonic relationship means every step toward the target is unambiguous: no need for a hash map since the sort order itself tells us which direction to move.

## Approach

1. Start `left` at the first index, `right` at the last.
2. Compute `sum = numbers[left] + numbers[right]`.
3. If `sum == target`, return the (1-indexed) positions.
4. If `sum < target`, the pair needs to be bigger — advance `left` (the only way to increase the sum while shrinking the search space).
5. If `sum > target`, retreat `right` (the only way to decrease the sum).
6. Repeat until the pointers find the target (guaranteed to exist).

## Edge Cases

- Guaranteed exactly one valid pair, so no need to handle "no solution" as a real case, though the loop naturally terminates if pointers cross.
- Negative numbers work fine — the monotonic sum argument doesn't depend on sign.
- Smallest possible array is size 2 — pointers start already adjacent to each other, one comparison resolves it.
- Contrast with the unsorted Two Sum (LC #1): here sortedness replaces the need for a hash map, trading O(n) space for O(1).
