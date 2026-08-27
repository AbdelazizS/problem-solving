# First Unique Character in a String

Difficulty:
Easy

Date:
2026-08-27

Week:
5

Time Taken:
__ min

## Pattern

Hash Map, Frequency Counting

## Complexity

| Approach                              | Time   | Space |
|------------------------------------------|--------|-------|
| Two-pass hash map (count, then scan)      | O(n)   | O(1) (bounded alphabet) |
| Brute force: for each char, count occurrences by scanning whole string | O(n^2) | O(1)  |

## Approach

1. Pass 1: build a full frequency count of every character in `s`.
2. Pass 2: walk `s` in original order; the first character whose stored count equals 1 is the answer — return its index immediately.
3. If the second pass completes with no match, return -1.

## Mistakes I Made

- Trying to solve it in a single pass by returning as soon as a character is seen for the "first time" — this is wrong because a character can look unique early on but repeat later in the string; you can't know it's globally unique without having seen the whole string first.
- Forgetting that "first" refers to position in the original string, not order of insertion into the hash map (which is why the second pass re-scans `s` rather than iterating the map).

## What I Learned

- This is the standard shape for problems needing both a *global* property (total frequency) and *positional* information (first occurrence) — count everything first, then make a second, order-preserving pass to answer using those counts.
- A single pass alone is insufficient whenever "uniqueness" depends on information that can only be confirmed after seeing the entire input.

## Interview Takeaways

- Justify the two-pass necessity explicitly — this is a common point of confusion, and stating it up front shows clear reasoning.
- Note the O(1) space claim depends on treating the alphabet as bounded/fixed (26 lowercase letters) — for a general Unicode string, space would be O(k) for k distinct characters.
- Mention this generalizes to "find the first element satisfying a property that depends on the whole collection" — same two-pass shape applies broadly.

## Similar Problems

- Ransom Note
- Valid Anagram
- Find the Difference
- Longest Substring Without Repeating Characters
