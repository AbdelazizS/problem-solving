# First Unique Character in a String

| Field      | Value     |
|------------|-----------|
| Pattern    | Hash Map, Frequency Counting |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1) (bounded alphabet) |
| Status     | Solved    |
| LeetCode   | [#387](https://leetcode.com/problems/first-unique-character-in-a-string/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given a string `s`, find the first non-repeating character in it and return its index. If none exists, return -1.

## Key Insight

"First" implies order matters, but "unique" is a global property (a character's total count across the whole string) that can't be determined by looking at it in isolation during a single left-to-right pass. This naturally splits into two passes: one to count everything, one to answer using those counts in the original order.

## Approach

1. First pass: count the frequency of every character into a hash map.
2. Second pass: scan `s` left to right again, and return the index of the first character whose count is exactly 1.
3. If no such character exists after scanning the whole string, return -1.

## Edge Cases

- Empty string → -1 (no characters at all).
- All characters repeated → -1.
- All characters unique → returns index 0 (the very first character).
- Since the alphabet is fixed (lowercase English letters), an `int[26]` array works identically to a hash map with O(1) space instead of O(k) for distinct characters.
