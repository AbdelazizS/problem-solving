# Permutations

Difficulty:
Medium

Date:
2026-09-07

Week:
6

Time Taken:
__ min

## Pattern

Backtracking, Used-Array

## Complexity

| Approach                                    | Time           | Space |
|-------------------------------------------------|----------------|-------|
| Backtracking with used[] array                     | O(n * n!)      | O(n) auxiliary (call stack + used array) |
| Heap's algorithm (in-place swapping)                | O(n!)          | O(n) recursion stack |

## Approach

1. `current` holds the partial permutation being built; `used[]` tracks which indices are already placed.
2. Base case: `current.size() == n` means a complete permutation is done — record a copy.
3. Otherwise, try every index not yet used: mark it used, append its value, recurse.
4. After the recursive call returns, undo both the append and the used-flag (backtrack) so the next candidate in the loop starts from a clean state.

## Mistakes I Made

- Trying to reuse the `start` index technique from Subsets — this is wrong here because permutations need every element eventually, in every position, not just elements from some point onward.
- Forgetting to reset `used[i] = false` after backtracking — without it, an element stays permanently excluded from later branches of the search tree, producing far fewer than `n!` results.

## What I Learned

- The `used[]` array (vs. a `start` index) is the key structural difference between "permutation-style" and "subset-style" backtracking: subsets pick a *subsequence* (order fixed, presence varies), permutations pick an *ordering* (all elements present, order varies).
- Recording the result only at the base case (not on every recursive call, unlike Subsets) reflects that only *complete* orderings are valid answers here — a partial ordering by itself isn't a permutation.

## Interview Takeaways

- Explicitly contrast this with Subsets when asked: same "choose, recurse, un-choose" skeleton, different exit condition and different mechanism for avoiding reuse.
- State the complexity honestly: there are `n!` permutations, each taking O(n) to copy into the result, giving O(n * n!) — this is inherent to the output size, not something to optimize away.
- Mention Heap's algorithm as an alternative that generates permutations via in-place adjacent swaps, avoiding the `used[]` array, if asked for a different technique.

## Similar Problems

- Permutations II (with duplicates)
- Subsets
- Combination Sum
- Next Permutation
