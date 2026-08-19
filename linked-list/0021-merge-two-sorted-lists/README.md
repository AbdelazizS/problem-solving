# Merge Two Sorted Lists

| Field      | Value     |
|------------|-----------|
| Pattern    | Linked List, Pointer Manipulation, Dummy Node |
| Difficulty | Easy      |
| Time       | O(n + m)  |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#21](https://leetcode.com/problems/merge-two-sorted-lists/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given the heads of two sorted linked lists, merge their existing nodes into one sorted linked list and return its head.

## Key Insight

Because both lists are sorted, the smaller current node is always the next node in the merged list. A dummy node gives the result a stable starting point and removes special handling for its first node.

## Approach

1. Create a dummy node and use `current` to build the merged list.
2. Compare the current nodes of both lists.
3. Attach the smaller node, then advance that list's pointer.
4. Attach the remaining non-empty list after one list is exhausted.
5. Return `dummy.next`.

## Edge Cases

- Either input list can be empty.
- Equal values can be taken from either list while preserving sorted order.
- The remaining tail can be attached directly because it is already sorted.
