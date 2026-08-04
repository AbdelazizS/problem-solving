# Valid Anagram

Difficulty:
Easy

Date:
2026-08-04

Week:
1

Time Taken:
35 min

## Pattern

Frequency Counting, Hash Map

## Complexity

| Approach        | Time       | Space |
|-----------------|------------|-------|
| Sort strings    | O(n log n) | O(n)  |
| Frequency count | O(n)       | O(1)  |

## Approach

1. Return `false` immediately if the strings have different lengths.
2. Create an array with 26 counters for lowercase English letters.
3. Scan both strings together: increment the counter for each character in `s` and decrement it for each character in `t`.
4. Return `false` if any counter is not zero; otherwise, return `true`.

## Mistakes I Made

- Check lengths first so strings with different character counts cannot be treated as anagrams.
- Use a hash map instead of a 26-element array if the input can contain arbitrary Unicode characters.

## What I Learned

- Frequency counting is a direct way to compare multisets of characters.
- When the alphabet size is fixed, the extra space is O(1).

## Interview Takeaways

- Mention sorting as a valid O(n log n) approach, then improve it with frequency counting.
- Ask whether input is limited to lowercase English letters before choosing a fixed-size array.
- Explain that each character count must balance to zero.

## Similar Problems

- Contains Duplicate
- Group Anagrams
- Find All Anagrams in a String
