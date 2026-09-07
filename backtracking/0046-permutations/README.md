# Permutations

| Field      | Value     |
|------------|-----------|
| Pattern    | Backtracking, Used-Array |
| Difficulty | Medium    |
| Time       | O(n &times; n!) |
| Space      | O(n) auxiliary (excluding output) |
| Status     | Solved    |
| LeetCode   | [#46](https://leetcode.com/problems/permutations/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an array of distinct integers, return all possible permutations (every ordering of all `n` elements).

## Key Insight

Unlike Subsets (where each element is independently in-or-out, and a `start` index prevents reuse), every permutation must use *every* element exactly once, just in a different order. That means any not-yet-used element can be picked next at any position — so instead of a `start` index, a `used[]` array tracks which elements are already placed in the current path, and the recursion tries every unused element at each step.

## Approach

1. Recurse with a `current` partial permutation and a `used[]` boolean array.
2. Base case: when `current` has length `n`, it's a complete permutation — record a copy of it.
3. Otherwise, loop over every index; skip any already-used element.
4. Mark the chosen element used, append it to `current`, recurse, then undo both (backtrack) before trying the next candidate.

## Edge Cases

- Single-element array → exactly one permutation (itself).
- Two elements → exactly 2 permutations (`n!` for n=2).
- The result is only recorded at the base case (full-length paths), unlike Subsets where every node in the recursion tree is a valid answer — this is the key structural difference between the two problems.
- With distinct integers, no permutation is ever produced twice; a version with duplicate input values would need extra de-duplication logic (sort + skip-equal-and-unused-previous), which this LeetCode variant doesn't require.
