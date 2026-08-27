# Longest Substring Without Repeating Characters

| Field      | Value     |
|------------|-----------|
| Pattern    | Sliding Window, Variable (Expand/Shrink) |
| Difficulty | Medium    |
| Time       | O(n)      |
| Space      | O(min(n, alphabet size)) |
| Status     | Solved    |
| LeetCode   | [#3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given a string `s`, find the length of the longest substring without repeating characters.

## Key Insight

A window `[left, right]` is valid exactly when it contains no duplicate characters. Expanding `right` one step at a time and shrinking `left` only when a duplicate is introduced keeps the window always as large as possible while remaining valid — every character enters and leaves the window at most once, giving a linear scan instead of checking every substring.

## Approach

1. Maintain a hash set of characters currently in the window `[left, right]`, plus a `maxLength` tracker.
2. Expand the window by moving `right` forward one character at a time.
3. If the new character is already in the window, shrink from the left (removing characters from the set and advancing `left`) until the duplicate is gone.
4. Add the new character to the set and update `maxLength` with the current window size (`right - left + 1`).
5. Continue until `right` reaches the end of the string.

## Edge Cases

- Empty string → 0.
- All identical characters (e.g. `"aaaa"`) → longest valid window is length 1.
- All distinct characters → the whole string is the answer.
- Every character enters and leaves the window at most once across the whole scan, so both pointers only ever move forward — this is what keeps the algorithm O(n) despite the nested-looking `while`.
