# Reverse Linked List

| Field      | Value     |
|------------|-----------|
| Pattern    | Linked List, Pointer Manipulation |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#206](https://leetcode.com/problems/reverse-linked-list/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given the head of a singly linked list, reverse the links and return the new head.

## Key Insight

Reversing a node's pointer would lose access to the rest of the list unless the next node is saved first. Keep `previous`, `current`, and `next` pointers to reverse one link at a time.

## Approach

1. Start with `previous` as `null` and `current` as the head.
2. Save `current.next` before changing the link.
3. Point `current.next` backward to `previous`.
4. Advance both pointers until `current` is `null`.
5. Return `previous` as the new head.

## Edge Cases

- An empty list returns `null`.
- A one-node list remains unchanged.
- The original head becomes the final node and must point to `null`.
