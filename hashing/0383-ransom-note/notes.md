# Ransom Note

Difficulty:
Easy

Date:
2026-08-25

Week:
4

Time Taken:
__ min

## Pattern

Hash Map, Frequency Counting

## Complexity

| Approach                          | Time       | Space |
|-------------------------------------|------------|-------|
| Hash map of magazine counts          | O(m + n)   | O(1) (bounded 26-letter alphabet) |
| Sort both strings and two-pointer    | O(m log m + n log n) | O(1) |

## Approach

1. Build a frequency map from `magazine`.
2. Walk `ransomNote`; for each character, fail fast if the map shows zero remaining.
3. Otherwise decrement and continue.
4. Success if the loop completes.

## Mistakes I Made

- Building a frequency map of `ransomNote` and comparing against a separate map of `magazine` instead of decrementing in place — works but is unnecessary extra bookkeeping.
- Forgetting the "fail fast" check and only validating counts after fully building both maps — correct but wastes the early-exit optimization.

## What I Learned

- "Can X be built from the letters of Y" is a classic frequency-counting signal: count once, then consume/decrement while scanning the other string.
- With a small fixed alphabet (lowercase English letters), an array is functionally a hash map with O(1) guaranteed non-colliding buckets — worth mentioning as the natural optimization.

## Interview Takeaways

- Frame it explicitly as supply (magazine) vs. demand (ransomNote).
- Mention the array-vs-hashmap trade-off: array is faster/simpler here because the alphabet is small and known; a general hash map is what to reach for with unbounded characters (Unicode, for example).
- State the early-exit optimization explicitly — no need to fully process ransomNote if we already know a letter is unavailable.

## Similar Problems

- Valid Anagram
- Find the Difference
- First Unique Character in a String
