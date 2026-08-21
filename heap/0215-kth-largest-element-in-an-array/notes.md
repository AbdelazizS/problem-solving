# Kth Largest Element in an Array

Difficulty:
Medium

Date:
2026-08-22

Week:
3

Time Taken:
__ min

## Pattern

Heap, Top K

## Complexity

| Approach                          | Time         | Space |
|-------------------------------------|--------------|-------|
| Sort descending, index k-1           | O(n log n)   | O(1) (or O(n) depending on sort) |
| Min-heap capped at size k            | O(n log k)   | O(k)  |
| Quickselect                          | O(n) average, O(n^2) worst | O(1) |

## Approach

1. Maintain a min-heap.
2. Push each number; if the heap size exceeds k, pop the minimum.
3. The heap always holds the k largest numbers seen so far; its top is the smallest of them.
4. After scanning all numbers, the top of the heap is the answer.

## Mistakes I Made

- Using a max-heap of the whole array first (O(n log n) to build, then k pops) instead of a bounded min-heap — works but is strictly worse when k is small relative to n.
- Forgetting the heap needs to be capped — an uncapped min-heap's top is the smallest element overall, not the k-th largest.

## What I Learned

- "Top K" problems are the strongest signal for a heap: keep a heap of size k, and the top of that heap is exactly the boundary value.
- A min-heap is used to find the k *largest* items (counterintuitively) because it lets you cheaply evict the smallest of the k candidates you're keeping.
- Quickselect trades average-case speed for worst-case risk and mutates input — good to mention as a follow-up in interviews even if the heap solution is the one implemented.

## Interview Takeaways

- State the invariant explicitly: "the heap always contains the k largest elements processed so far."
- Justify why min-heap and not max-heap: we need cheap access to the *smallest* of our k candidates to know what to evict.
- Bring up quickselect as the O(n) average alternative if asked to optimize further.

## Similar Problems

- Top K Frequent Elements
- K Closest Points to Origin
- Find Median from Data Stream
- Kth Smallest Element in a Sorted Matrix
