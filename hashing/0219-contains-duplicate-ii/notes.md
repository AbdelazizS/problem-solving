# Contains Duplicate II

Difficulty:
Easy

Date:
2026-08-26

Week:
4

Time Taken:
__ min

## Pattern

Hash Map, Index Tracking

## Complexity

| Approach                                   | Time | Space |
|----------------------------------------------|------|-------|
| Hash map: value → last seen index             | O(n) | O(min(n, k)) |
| Sliding window of size k as a hash set        | O(n) | O(k)  |

## Approach

1. Walk the array once, tracking each value's last seen index in a hash map.
2. On seeing a value again, check if the index gap is within `k`; if so, return true.
3. Always overwrite the stored index with the current one — the most recent occurrence is always the best candidate for a future nearby match.
4. No match found by the end → return false.

## Mistakes I Made

- Keeping only the *first* occurrence's index instead of the most recent — this misses valid matches when a value repeats more than twice with increasing gaps from the first occurrence but a close gap between later occurrences.
- Initially reaching for a full O(n^2) pairwise comparison before recognizing the O(n) single-pass hash map approach.

## What I Learned

- When a "nearby" or "within distance k" constraint is added to a duplicate-detection problem, the pattern upgrades from a hash *set* (membership only) to a hash *map* (membership + extra info, here the index).
- An equivalent framing is a sliding window of size k maintained as a hash set — conceptually the same bound, different implementation.

## Interview Takeaways

- Explain explicitly why a map, not a set, is needed here: we need *where* we last saw the value, not just *that* we saw it.
- State clearly why always updating to the most recent index is correct and never loses a valid answer.
- Mention the fixed-size sliding-window-as-set framing as an alternative implementation with the same complexity.

## Similar Problems

- Contains Duplicate
- Contains Duplicate III
- Longest Substring Without Repeating Characters
