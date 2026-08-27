# Longest Substring Without Repeating Characters

Difficulty:
Medium

Date:
2026-08-27

Week:
5

Time Taken:
__ min

## Pattern

Sliding Window, Variable (Expand/Shrink)

## Complexity

| Approach                                        | Time   | Space |
|------------------------------------------------------|--------|-------|
| Brute force: check every substring for duplicates       | O(n^3) or O(n^2) | O(min(n, alphabet)) |
| Sliding window with hash set                            | O(n)   | O(min(n, alphabet size)) |
| Sliding window with hash map (jump left directly)        | O(n)   | O(min(n, alphabet size)) |

## Approach

1. `left` and `right` define the current window; a hash set tracks which characters are inside it.
2. Advance `right`, adding characters to the window.
3. Whenever the incoming character is already in the window, shrink from `left` (removing characters, advancing `left`) until it's no longer a duplicate.
4. After the window is valid, record its length if it's the best seen so far.

## Mistakes I Made

- Shrinking the window one step and re-checking from scratch, instead of only shrinking until the *specific* duplicate is removed — the `while (window.contains(c))` loop naturally handles this correctly, but it's easy to write an `if` instead of a `while` and get a subtly wrong answer.
- Not realizing that using a hash *map* (character → last seen index) instead of a set lets `left` jump directly to `lastIndex + 1` instead of shrinking one character at a time — a nice O(n) optimization with a better constant factor, though same asymptotic complexity.

## What I Learned

- This is the canonical "variable-size window" template: expand with `right`, shrink with `left` only while the window is invalid, track the best valid window size seen.
- Both pointers only ever move forward across the whole algorithm — this amortized argument is what makes it O(n) instead of O(n^2), even though there's a nested-looking loop.

## Interview Takeaways

- State the amortized complexity argument explicitly: `left` and `right` together each traverse the string at most once, so total work is O(n) even with the inner while loop.
- Mention the hash-map optimization (jump `left` directly to `lastSeenIndex + 1`) as a natural follow-up if asked to reduce constant factor.
- Contrast with the fixed-size window from Maximum Average Subarray I — here the window size itself is what's being optimized, not fixed in advance.

## Similar Problems

- Longest Repeating Character Replacement
- Minimum Window Substring
- Permutation in String
- Max Consecutive Ones III
