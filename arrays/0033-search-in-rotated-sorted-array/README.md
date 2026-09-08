# Search in Rotated Sorted Array

| Field      | Value     |
|------------|-----------|
| Pattern    | Binary Search, Modified (Rotated Array) |
| Difficulty | Medium    |
| Time       | O(log n)  |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#33](https://leetcode.com/problems/search-in-rotated-sorted-array/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given a sorted array that has been rotated at an unknown pivot, and a target value, return the index of `target` if it exists, or -1 otherwise, in O(log n) time.

## Key Insight

A rotated sorted array isn't fully sorted, but at any midpoint, at least one of the two halves (`[left, mid]` or `[mid, right]`) is guaranteed to be normally sorted. Once we know which half is sorted, we can cheaply check whether the target falls within that half's known range — if it does, recurse into it; if not, the target must be in the other (still-rotated) half.

## Approach

1. Standard binary search skeleton: `left`, `right`, compute `mid`, compare `nums[mid]` to `target`.
2. Determine which half is sorted by comparing `nums[left]` to `nums[mid]`: if `nums[left] <= nums[mid]`, the left half is sorted; otherwise the right half is sorted.
3. If the left half is sorted, check whether `target` falls within `[nums[left], nums[mid])` — if so, search left; otherwise search right.
4. If the right half is sorted, check whether `target` falls within `(nums[mid], nums[right]]` — if so, search right; otherwise search left.
5. Repeat until found or the search space is exhausted (return -1).

## Edge Cases

- No rotation (array is fully sorted) → behaves identically to plain binary search.
- Rotation point at index 0 or the last index → still handled correctly since the "which half is sorted" check works for any rotation amount, including none.
- Target not present → search space shrinks to empty, returns -1.
- Single element array → loop runs once, trivially resolved.
- Duplicate values would break the "which half is sorted" determination (LeetCode's follow-up, Search in Rotated Sorted Array II) — this variant assumes all elements are distinct.
