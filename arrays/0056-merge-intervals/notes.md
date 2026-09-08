# Merge Intervals

Difficulty:
Medium

Date:
2026-09-08

Week:
6

Time Taken:
__ min

## Pattern

Sorting, Interval Merging

## Complexity

| Approach                                     | Time         | Space |
|--------------------------------------------------|--------------|-------|
| Brute force: pairwise overlap checks + merge         | O(n^2)       | O(n)  |
| Sort by start, single linear merge pass                | O(n log n)   | O(n)  |

## Approach

1. Sort intervals by their start value — this is what makes a single pass sufficient.
2. Walk the sorted intervals, keeping a `merged` result list.
3. Compare each interval's start against the last merged interval's end: overlap (`start <= lastEnd`) means extend; no overlap means start a new entry.
4. Extending always takes the max of the two ends, since a later interval can be fully contained within an earlier, wider one.

## Mistakes I Made

- Forgetting to sort first and trying to merge directly — without sorting, an interval's overlap with *any* other interval (not just the adjacent one) has to be checked, which is what forces the naive O(n^2) approach.
- Using `lastEnd < currentEnd` instead of `max(lastEnd, currentEnd)` when merging — this silently shrinks the merged interval's end if a later, fully-contained interval happens to have a smaller end value than the one already merged.

## What I Learned

- Sorting is often the "free" preprocessing step that turns an all-pairs comparison problem into a single linear scan — the key question to ask is "what property becomes true, and useful, once this data is sorted?"
- Here, sorting by start value means overlap can only ever be checked against the *most recently merged* interval, never anything further back — this locality is what collapses O(n^2) into O(n log n).

## Interview Takeaways

- State explicitly why sorting first is necessary: it guarantees that if interval `i` doesn't overlap the current merged interval, no interval after `i` can overlap it either (since all later starts are `>=` interval `i`'s start).
- Call out the `max(lastEnd, currentEnd)` detail as a common off-by-mistake, and explain the contained-interval case it protects against.
- Mention this is the classic template for interval scheduling problems more broadly — Insert Interval, Non-overlapping Intervals, and Meeting Rooms all build on the same sort-then-scan idea.

## Similar Problems

- Insert Interval
- Non-overlapping Intervals
- Meeting Rooms
- Meeting Rooms II
