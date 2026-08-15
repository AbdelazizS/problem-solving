# Intersection of Two Arrays

Difficulty:
Easy

Date:
2026-08-15

Week:
2

Time Taken:
__ min

## Pattern

Sorting, Two Pointers

## Complexity

| Approach              | Time               | Space |
|-----------------------|--------------------|-------|
| Hash set              | O(n + m)           | O(n + m) |
| Sort + two pointers   | O(n log n + m log m) | O(log n + log m), excluding output |

## Approach

1. Sort both input arrays so equal values can be aligned.
2. Compare the values at the two pointers.
3. Move the pointer that points to the smaller value.
4. When both values are equal, add the value once and move both pointers.
5. Skip repeated matches by checking the last value added to the result.

## Mistakes I Made

- Do not add the same matching value more than once.
- Sorting changes the input arrays; use copies if their original order must be preserved.
- Move only the pointer with the smaller value so a possible match is not skipped.

## What I Learned

- Sorting turns an unordered membership problem into an ordered scan.
- Two pointers make it possible to traverse both sorted arrays in linear time after sorting.

## Interview Takeaways

- Mention the hash-set solution when extra space is acceptable.
- Choose sorting plus two pointers when the problem asks you to use sorting or when ordered input is useful.
- Confirm whether modifying the input arrays is allowed.

## Similar Problems

- Intersection of Two Arrays II
- 3Sum
- Merge Sorted Array
