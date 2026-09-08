# Search in Rotated Sorted Array

Difficulty:
Medium

Date:
2026-09-08

Week:
6

Time Taken:
__ min

## Pattern

Binary Search, Modified (Rotated Array)

## Complexity

| Approach                                       | Time      | Space |
|-----------------------------------------------------|-----------|-------|
| Linear scan                                            | O(n)      | O(1)  |
| Find rotation pivot first, then binary search twice       | O(log n)  | O(1)  |
| Single-pass modified binary search (this solution)          | O(log n)  | O(1)  |

## Approach

1. Maintain `left`/`right` pointers like standard binary search.
2. At each `mid`, first check for a direct hit.
3. Determine which side is "normally sorted" by comparing `nums[left]` to `nums[mid]`.
4. Within the sorted side, a simple range check (`nums[left] <= target < nums[mid]`, or the mirrored version for the right side) tells you definitively whether `target` could be there.
5. Narrow the search to whichever half could contain the target; repeat.

## Mistakes I Made

- Trying to first locate the rotation pivot with one binary search, then run a second binary search on the appropriate half — correct, but more code than necessary; the single-pass version folds pivot-awareness directly into each iteration's decision.
- Getting the boundary conditions backwards (`<=` vs `<`) when checking whether `target` falls in the sorted half's range — off-by-one errors here silently exclude the boundary values themselves from being found.

## What I Learned

- The key generalization from plain binary search: you don't need the *whole* array sorted to binary search it — you only need, at every step, a decidable way to determine which half to discard. Here that's "which half is sorted, and does the target's value fall within that half's known bounds."
- This modified binary search technique reappears in Find Minimum in Rotated Sorted Array and Search in Rotated Sorted Array II (with duplicates, where the "which half is sorted" check can become ambiguous and degrades to O(n) worst case).

## Interview Takeaways

- Draw the rotated array and explicitly point out that no matter where `mid` lands, one of the two halves must still be in ascending order — that's the load-bearing observation.
- Justify the O(log n) bound: each iteration eliminates half the search space, exactly like standard binary search, just with an extra comparison to decide which half to keep.
- Mention the duplicates follow-up and why it breaks the guarantee (when `nums[left] == nums[mid] == nums[right]`, you can't tell which half is sorted without potentially scanning).

## Similar Problems

- Find Minimum in Rotated Sorted Array
- Search in Rotated Sorted Array II
- Find Peak Element
- Binary Search
