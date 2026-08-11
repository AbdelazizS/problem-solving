# Binary Search

Difficulty:
Easy

Date:
2026-08-11

Week:
2

Time Taken:
__ min

## Pattern

Binary Search

## Complexity

| Approach       | Time     | Space |
|----------------|----------|-------|
| Linear search  | O(n)     | O(1)  |
| Binary search  | O(log n) | O(1)  |

## Approach

1. Set `left` to the first index and `right` to the last index.
2. While `left` is not past `right`, calculate the middle index.
3. Return the middle index if its value equals the target.
4. Search the right half when the middle value is smaller; otherwise search the left half.
5. Return `-1` if the search space becomes empty.

## Mistakes I Made

- Binary search needs sorted input.
- Use `left + (right - left) / 2` to avoid potential overflow.
- Use `left <= right` when both boundaries are inclusive.

## What I Learned

- Each comparison discards half of the remaining search space.
- Binary search applies to answer spaces as well as sorted arrays.

## Interview Takeaways

- Confirm that the input is sorted before selecting this approach.
- Explain the search invariant: if the target exists, it remains between `left` and `right`.
- Test targets at the beginning, middle, end, and outside the array range.

## Similar Problems

- Search Insert Position
- Find First and Last Position of Element in Sorted Array
- Search in Rotated Sorted Array
