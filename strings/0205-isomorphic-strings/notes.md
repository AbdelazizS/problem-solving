# Isomorphic Strings

Difficulty:
Easy

Date:
2026-08-20

Week:
1

Time Taken:
__ min

## Pattern

Hash Map, Bidirectional Mapping

## Complexity

| Approach                 | Time  | Space |
|--------------------------|-------|-------|
| Compare every replacement | O(n²) | O(n)  |
| Two hash maps            | O(n)  | O(n)  |

## Approach

1. Create one map from characters in `s` to characters in `t`.
2. Create a second reverse map from `t` to `s`.
3. For each character pair, reject conflicting mappings in either direction.
4. Store the valid pair in both maps.

## Mistakes I Made

- One forward map alone does not prevent two source characters from mapping to the same target.
- Check an existing mapping before overwriting it.
- Confirm the strings have the same length before comparing them.

## What I Learned

- Hash maps can represent relationships, not only counts or membership.
- A bijection requires a consistent mapping in both directions.

## Interview Takeaways

- State the difference between a one-way mapping and a one-to-one mapping.
- Test repeated characters: `"egg"` with `"add"` is valid, but `"foo"` with `"bar"` is not.
- Explain why reverse mapping prevents collisions.

## Similar Problems

- Word Pattern
- Valid Anagram
- Find and Replace Pattern
