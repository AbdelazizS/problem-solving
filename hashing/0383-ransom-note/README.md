# Ransom Note

| Field      | Value     |
|------------|-----------|
| Pattern    | Hash Map, Frequency Counting |
| Difficulty | Easy      |
| Time       | O(m + n)  |
| Space      | O(1) (bounded alphabet) |
| Status     | Solved    |
| LeetCode   | [#383](https://leetcode.com/problems/ransom-note/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given two strings `ransomNote` and `magazine`, return true if `ransomNote` can be constructed by cutting out individual letters from `magazine`, where each letter in `magazine` can be used only once.

## Key Insight

This is a supply-vs-demand counting problem: build a frequency map of the "supply" (`magazine`), then walk the "demand" (`ransomNote`) decrementing available counts. If any character is ever needed but unavailable, construction is impossible.

## Approach

1. Count every character's frequency in `magazine` into a hash map.
2. For each character in `ransomNote`, check the map has at least one remaining; if not, return false immediately.
3. Otherwise, decrement that character's count and continue.
4. If the whole `ransomNote` is consumed without running out, return true.

## Edge Cases

- Empty `ransomNote` → always true (nothing needed).
- `magazine` shorter than `ransomNote` → will always fail once supply runs out.
- Repeated letters in `ransomNote` require that many occurrences in `magazine`, not just one.
- Since input is lowercase English letters, a fixed-size `int[26]` array is a valid space optimization over a general hash map.
