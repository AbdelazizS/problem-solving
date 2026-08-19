# Merge Two Sorted Lists

Difficulty:
Easy

Date:
2026-08-20

Week:
2

Time Taken:
__ min

## Pattern

Linked List, Pointer Manipulation, Dummy Node

## Complexity

| Approach             | Time     | Space |
|----------------------|----------|-------|
| Copy values and sort | O((n + m) log(n + m)) | O(n + m) |
| Merge pointers       | O(n + m) | O(1)  |

## Approach

1. Use a dummy node to begin the result list.
2. Compare `list1` and `list2` while both contain nodes.
3. Append the smaller node to the result and advance its source pointer.
4. Attach the nodes remaining in the non-empty list.
5. Return the node after the dummy.

## Mistakes I Made

- Return `dummy.next`, not the dummy node itself.
- Do not create new nodes for every value; reuse the nodes already in the input lists.
- Remember to attach the remaining list after the comparison loop ends.

## What I Learned

- Sorted input makes a one-pass merge possible.
- A dummy node simplifies linked-list construction by avoiding a special first-node case.

## Interview Takeaways

- State the invariant: the list after `dummy` is always sorted.
- Explain that every node is attached once, producing O(n + m) time.
- Test empty lists, unequal lengths, and duplicate values.

## Similar Problems

- Merge k Sorted Lists
- Merge Sorted Array
- Sort List
