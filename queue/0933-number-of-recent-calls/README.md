# Number of Recent Calls

| Field      | Value     |
|------------|-----------|
| Pattern    | Queue, FIFO |
| Difficulty | Easy      |
| Time       | O(1) amortized per `ping` |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#933](https://leetcode.com/problems/number-of-recent-calls/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Design a counter that returns the number of requests received in the inclusive time range `[t - 3000, t]` for every `ping(t)` call.

## Key Insight

Timestamps arrive in increasing order, so requests that become too old will never become relevant again. A queue keeps requests in arrival order and removes expired requests from its front.

## Approach

1. Add the current timestamp to the back of the queue.
2. Remove timestamps from the front while they are older than `t - 3000`.
3. Return the queue size.

## Edge Cases

- A timestamp exactly equal to `t - 3000` remains in the valid range.
- Several requests can share nearby timestamps and all remain counted when valid.
- Each timestamp enters and leaves the queue at most once.
