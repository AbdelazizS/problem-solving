# Isomorphic Strings

| Field      | Value     |
|------------|-----------|
| Pattern    | Hash Map, Bidirectional Mapping |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#205](https://leetcode.com/problems/isomorphic-strings/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given two strings, return whether each character in the first string can be replaced consistently to produce the second string.

## Key Insight

An isomorphic mapping must be one-to-one. Track mappings in both directions so one source character cannot map to different targets and two source characters cannot map to the same target.

## Approach

1. Scan both strings at the same index.
2. Check whether the source character already has a conflicting target mapping.
3. Check whether the target character already has a conflicting source mapping.
4. Store both mappings and continue.

## Edge Cases

- Repeated characters must always map to the same character.
- Different source characters cannot share one target character.
- Strings of unequal lengths cannot be isomorphic.
