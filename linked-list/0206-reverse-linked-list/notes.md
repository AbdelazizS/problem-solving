# Reverse Linked List

Difficulty:
Easy

Date:
2026-08-19

Week:
2

Time Taken:
__ min

## Pattern

Linked List, Pointer Manipulation

## Complexity

| Approach             | Time | Space |
|----------------------|------|-------|
| Iterative reversal   | O(n) | O(1)  |
| Recursive reversal   | O(n) | O(n)  |

## Approach

1. Keep `previous` for the already-reversed portion of the list.
2. Keep `current` for the node being processed.
3. Save `next` before redirecting `current.next` to `previous`.
4. Move `previous` and `current` forward.
5. Return `previous` after all nodes are processed.

## Mistakes I Made

- Save the next node before overwriting the current node's `next` pointer.
- Do not return the original head; after reversal, `previous` is the new head.
- Handle an empty list without dereferencing `null`.

## What I Learned

- Linked-list changes are made by rewiring node references, not by rearranging an array.
- Three pointers are enough to reverse a singly linked list in place.

## Interview Takeaways

- Draw the pointer changes for a short list before coding.
- State that each node is visited once and no extra collection is needed.
- Explain why saving `next` prevents losing the unreversed portion.

## Similar Problems

- Reverse Linked List II
- Reverse Nodes in k-Group
- Palindrome Linked List
