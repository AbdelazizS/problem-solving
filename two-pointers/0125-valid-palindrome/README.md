# Valid Palindrome

| Field      | Value     |
|------------|-----------|
| Pattern    | Two Pointers, Opposite Ends |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#125](https://leetcode.com/problems/valid-palindrome/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given a string `s`, return true if it's a palindrome after converting all uppercase letters to lowercase and removing all non-alphanumeric characters.

## Key Insight

Checking a palindrome from both ends at once avoids building a cleaned copy of the string first — two pointers can skip irrelevant characters and compare relevant ones in a single O(1)-space pass, converging toward the middle.

## Approach

1. Start `left` at index 0 and `right` at the last index.
2. Advance `left` forward while it points at a non-alphanumeric character; retreat `right` backward while it points at a non-alphanumeric character.
3. Once both point at alphanumeric characters, compare them case-insensitively; mismatch → return false immediately.
4. Move both pointers inward and repeat until they meet or cross.
5. If the loop completes without mismatch, the string is a palindrome.

## Edge Cases

- Empty string or all-non-alphanumeric string → vacuously true.
- Mixed case must be compared case-insensitively (`"Aa"` is a palindrome).
- Punctuation/spaces/symbols must be skipped entirely, not treated as mismatches.
- Single character → always true (pointers start equal, loop never runs).
