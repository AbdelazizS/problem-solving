# Contains Duplicate

Difficulty:
Easy

Date:
2026-08-02

Week:
1

Time Taken:
__ min

## Pattern

Hash Set

## Complexity

| Approach    | Time  | Space |
|-------------|-------|-------|
| Brute Force | O(n²) | O(1)  |
| Optimal     | O(n)  | O(n)  |

## Approach

1. Create an empty hash set named `seen`.
2. Scan every number in the array.
3. If the number is already in `seen`, return `true`.
4. Otherwise, add the number to `seen` and continue.
5. Return `false` if the scan finishes without a duplicate.

## Mistakes I Made

- Do not use nested loops when a hash set can detect a duplicate during one scan.
- Remember that `HashSet.add()` in Java returns `false` when the value already exists.

## What I Learned

- A hash set is the right tool when only membership matters.
- Early return avoids unnecessary work after finding the first duplicate.

## Interview Takeaways

- Start with the O(n²) pairwise comparison approach, then optimize with a hash set.
- State that hash-set operations are O(1) on average.
- Confirm whether modifying or sorting the input array is allowed before using a sorting solution.

## Similar Problems

- Valid Anagram
- Happy Number
- Longest Consecutive Sequence
