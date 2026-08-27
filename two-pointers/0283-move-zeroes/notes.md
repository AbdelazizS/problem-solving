# Move Zeroes

Difficulty:
Easy

Date:
2026-08-22

Week:
3

Time Taken:
__ min

## Pattern

Two Pointers, Read/Write (Same Direction)

## Complexity

| Approach                                          | Time | Space |
|------------------------------------------------------|------|-------|
| Copy non-zeros to new array, fill rest with zeros      | O(n) | O(n)  |
| Read/write two pointers, swap in place                 | O(n) | O(1)  |

## Approach

1. `writePos` marks the boundary: everything before it is the correctly-ordered non-zero prefix built so far.
2. `readPos` scans forward through the whole array.
3. On a non-zero at `readPos`, swap it with whatever sits at `writePos`, then advance `writePos`.
4. By the end, all non-zeros occupy `[0, writePos)` in original relative order, and all zeros have been pushed into `[writePos, n)`.

## Mistakes I Made

- Using assignment (`nums[writePos] = nums[readPos]`) without preserving what was overwritten — loses track of where zeros need to end up, unlike the swap approach which naturally relocates them.
- Confusing this with the "remove element" in-place pattern (overwrite only, no swap) — that pattern doesn't need to preserve the removed values anywhere, but this one needs zeros to still exist at the end, just moved.

## What I Learned

- This is the "read/write pointer" variant of two pointers (as opposed to opposite-ends): both pointers move in the same direction, with `writePos` always `<= readPos`, tracking a boundary between "finalized" and "still being scanned" regions.
- Swapping (not just overwriting) is what makes it work when both the placed and displaced values need to end up somewhere valid in the same array.

## Interview Takeaways

- State the invariant clearly: after processing index `readPos`, `nums[0..writePos)` contains exactly the non-zero elements seen so far, in original order.
- Explain why swap (not plain overwrite) is required: it relocates the zero being displaced rather than discarding information.
- Mention this same read/write shape applies to "remove duplicates from sorted array" and "remove element" problems, with different conditions for when to advance `writePos`.

## Similar Problems

- Remove Element
- Remove Duplicates from Sorted Array
- Sort Colors (Dutch National Flag, three-pointer variant)
