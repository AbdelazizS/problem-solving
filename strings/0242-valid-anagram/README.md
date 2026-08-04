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
