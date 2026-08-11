# Valid Anagram

| Field      | Value     |
|------------|-----------|
| Pattern    | Frequency Counting, Hash Map |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#242](https://leetcode.com/problems/valid-anagram/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`; otherwise, return `false`.

## Key Insight

Anagrams have the same frequency for every character. Increase counts for `s` and decrease them for `t`; every final count must be zero.

## Approach

1. Return `false` if the strings have different lengths.
2. Use a 26-element frequency array for lowercase English letters.
3. Increment counts for `s` and decrement them for `t` in one pass.
4. Return `true` only when every count is zero.

## Edge Cases

- Empty strings are anagrams of each other.
- This O(1)-space implementation relies on the lowercase English-letter constraint; use a hash map for a broader character set.
