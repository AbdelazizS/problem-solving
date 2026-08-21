# Subsets

Difficulty:
Medium

Date:
2026-08-22

Week:
3

Time Taken:
__ min

## Pattern

Backtracking, Include/Exclude

## Complexity

| Approach                          | Time         | Space |
|-------------------------------------|--------------|-------|
| Backtracking (start-index recursion) | O(n * 2^n)   | O(n) auxiliary (call stack + current path) |
| Iterative (bit-mask over 2^n)        | O(n * 2^n)   | O(n) auxiliary |

## Approach

1. Recurse on `(start, current)`.
2. Record `current` as a valid subset on every call entry, not just at a "final" base case — every partial path is itself an answer.
3. For each index from `start` onward, add it to `current`, recurse forward (`i + 1`), then remove it (backtrack) before moving to the next index.
4. The recursion naturally terminates when `start` passes the last index.

## Mistakes I Made

- Recursing with `start = i` instead of `i + 1` — produces infinite recursion / reuses elements.
- Forgetting to copy `current` (`new ArrayList<>(current)`) when adding to the result — without the copy, every stored subset is a reference to the same mutating list, so all results end up equal to whatever `current` ends up as.
- Only adding to the result at a "base case" instead of on every call — subsets don't have a fixed length, so every node in the recursion tree is itself a valid answer.

## What I Learned

- Backtracking = explicit DFS over a decision tree, with "choose, recurse, un-choose" as the core loop.
- The `start` index (rather than a `used[]` boolean array) is the standard way to avoid picking the same element twice and avoid generating the same subset in a different order, when elements are used at most once and order doesn't matter.
- This is the simplest backtracking template — Combination Sum and Permutations both build directly on this shape with small variations (reusing `i` instead of `i+1` for unlimited reuse; tracking `used[]` when order matters).

## Interview Takeaways

- Explain why the result is recorded at every node, not just leaves: the problem asks for subsets of every length, not just maximal ones.
- State the complexity honestly: 2^n subsets total, each up to O(n) to copy, so O(n * 2^n) overall — dominated by output size, which is unavoidable for this problem.
- Walk through the "choose / explore / un-choose" loop out loud — that's the core communication pattern for any backtracking answer.

## Similar Problems

- Subsets II (with duplicates)
- Combination Sum
- Permutations
- Letter Combinations of a Phone Number
