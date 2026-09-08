# Subarray Sum Equals K

Difficulty:
Medium

Date:
2026-09-08

Week:
6

Time Taken:
__ min

## Pattern

Prefix Sum + Hash Map

## Complexity

| Approach                                        | Time   | Space |
|-----------------------------------------------------|--------|-------|
| Brute force: check every subarray sum                  | O(n^2) | O(1)  |
| Prefix sum array + nested loop lookup                    | O(n^2) | O(n)  |
| Prefix sum + hash map of counts (this solution)            | O(n)   | O(n)  |

## Approach

1. Track a running prefix sum and a hash map of "prefix sum value → how many times seen."
2. At each element, before updating the map, check how many earlier prefixes equal `currentPrefixSum - k` — each one marks a valid subarray ending here.
3. Add that count to the running total.
4. Update the map with the current prefix sum, then move on.

## Mistakes I Made

- Forgetting to seed the map with `{0: 1}` — without it, subarrays starting from index 0 that sum exactly to `k` are silently missed, since there's no "empty prefix" entry to match against.
- Initially reaching for a plain prefix-sum array with a nested loop to compare pairs (O(n^2)) before recognizing the hash-map lookup collapses that inner loop to O(1).
- Sliding window instinct (since this "smells" like a subarray problem) — doesn't work here because the array can contain negative numbers, so there's no monotonic way to decide when to shrink the window.

## What I Learned

- "Number of subarrays summing to X" is the classic prefix-sum-plus-hashmap signal: rephrase "does subarray (i, j] sum to k" as "does an earlier prefix sum equal currentPrefixSum - k," then it's a counting/lookup problem, not a comparison problem.
- The `{0: 1}` seed is a recurring trick whenever a prefix-based technique needs to represent "the subarray starting from the very beginning" without special-casing it separately.
- This is fundamentally different from a sliding-window problem despite looking similar — negative numbers break the window's shrink/expand monotonicity, so hashing prefix sums is the correct generalization.

## Interview Takeaways

- Derive the transformation explicitly: `sum(i+1, j) = prefixSum[j] - prefixSum[i]`, so "subarray sums to k" becomes "does `prefixSum[i] == prefixSum[j] - k` exist for some `i < j`."
- Explain why sliding window doesn't apply here (negative numbers break monotonic window growth) — this is a common point where interviewers probe understanding.
- Justify the `{0: 1}` initialization out loud — it's a small detail that's easy to get right by rote but should be explained, not just remembered.

## Similar Problems

- Range Sum Query — Immutable
- Continuous Subarray Sum
- Subarray Sums Divisible by K
- Maximum Size Subarray Sum Equals k
