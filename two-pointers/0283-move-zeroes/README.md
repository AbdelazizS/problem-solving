# Move Zeroes

| Field      | Value     |
|------------|-----------|
| Pattern    | Two Pointers, Read/Write (Same Direction) |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#283](https://leetcode.com/problems/move-zeroes/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an integer array `nums`, move all `0`s to the end while maintaining the relative order of the non-zero elements, in place, without making a copy of the array.

## Key Insight

A read pointer scans every element once; a write pointer tracks where the next non-zero element belongs. Since `writePos` never outpaces `readPos`, swapping the two positions whenever a non-zero is found both places it correctly and pushes whatever was at `writePos` (always a zero or already-placed value) toward the back — achieving the move without a second array.

## Approach

1. Initialize `writePos = 0`.
2. Scan with `readPos` from 0 to the end.
3. Whenever `nums[readPos]` is non-zero, swap it into `nums[writePos]` and advance `writePos`.
4. Zeros are implicitly left behind at `readPos` (via the swap) and end up shifted toward the back as the scan continues.

## Edge Cases

- Array with no zeros → every element swaps with itself; array unchanged.
- Array of all zeros → `writePos` never advances; array unchanged (all zeros, which is already correct).
- Zeros already at the end → still correct, just redundant swaps.
- Relative order of non-zero elements is preserved because they're only ever moved earlier (never reordered among themselves).
