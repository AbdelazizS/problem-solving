# Merge Intervals

| Field      | Value     |
|------------|-----------|
| Pattern    | Sorting, Interval Merging |
| Difficulty | Medium    |
| Time       | O(n log n) |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#56](https://leetcode.com/problems/merge-intervals/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an array of intervals `[start, end]`, merge all overlapping intervals and return the resulting non-overlapping intervals, sorted.

## Key Insight

Overlap between arbitrary, unsorted intervals is hard to detect without comparing every pair. But once intervals are sorted by start time, overlap detection collapses to a single local comparison: an interval overlaps the most-recently-merged interval exactly when its start is `<=` that merged interval's end. This turns interval merging into a single linear pass after the sort.

## Approach

1. Sort intervals by start value.
2. Initialize a result list with the first interval.
3. For each subsequent interval, compare its start to the end of the last interval in the result:
   - If it starts after the last one ends (no overlap), append it as a new interval.
   - Otherwise (overlap), merge by extending the last interval's end to `max(lastEnd, currentEnd)`.
4. Return the accumulated result.

## Edge Cases

- Empty input → empty output.
- Single interval → returned unchanged.
- All intervals overlap into one → result is a single merged interval.
- No intervals overlap at all → result equals the sorted input, unchanged.
- An interval fully contained within another (e.g. `[1,10]` then `[2,5]`) → correctly absorbed since `max(lastEnd, currentEnd)` never shrinks the merged end.
