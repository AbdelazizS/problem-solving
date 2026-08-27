# Valid Palindrome

Difficulty:
Easy

Date:
2026-08-22

Week:
3

Time Taken:
__ min

## Pattern

Two Pointers, Opposite Ends

## Complexity

| Approach                                     | Time | Space |
|-------------------------------------------------|------|-------|
| Build cleaned string, compare to its reverse      | O(n) | O(n)  |
| Two pointers from opposite ends, in place         | O(n) | O(1)  |

## Approach

1. `left` starts at the front, `right` at the back.
2. Skip non-alphanumeric characters by advancing/retreating the relevant pointer without comparing.
3. When both pointers sit on alphanumeric characters, compare them case-insensitively.
4. Any mismatch short-circuits to false; otherwise pointers keep closing in until they meet.

## Mistakes I Made

- Building a fully cleaned/lowercased copy of the string first, then checking it equals its reverse — correct but O(n) extra space when it's avoidable.
- Forgetting `continue` after skipping a non-alphanumeric character, which caused a stale character to be compared on the same loop iteration.

## What I Learned

- The "opposite ends" two-pointer variant is the natural fit whenever a property needs to be checked symmetrically from both sides toward the middle (palindromes, reversing in place, etc.).
- Skipping irrelevant characters on each pointer independently (rather than pre-filtering the whole string) is what gets this down to O(1) space.

## Interview Takeaways

- Explicitly state the invariant: everything already compared (outside `[left, right]`) is confirmed to match; the answer is undetermined only within the current window.
- Mention the O(n) extra-space alternative (clean + reverse + compare) and why the two-pointer version improves on it.
- Watch for off-by-one / pointer-crossing edge cases when both pointers try to skip non-alphanumeric characters in the same iteration.

## Similar Problems

- Valid Palindrome II (one deletion allowed)
- Reverse String
- Palindrome Linked List
