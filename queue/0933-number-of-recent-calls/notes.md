# Number of Recent Calls

Difficulty:
Easy

Date:
2026-08-18

Week:
2

Time Taken:
__ min

## Pattern

Queue, FIFO

## Complexity

| Approach                 | Time per query | Space |
|--------------------------|----------------|-------|
| Scan all past timestamps | O(n)           | O(n)  |
| Queue                    | O(1) amortized | O(n)  |

## Approach

1. Store every still-relevant request timestamp in a queue.
2. Add the timestamp from the current `ping(t)` call.
3. Remove requests whose timestamp is less than `t - 3000`.
4. Return the number of timestamps remaining in the queue.

## Mistakes I Made

- The valid window is inclusive, so remove timestamps only when they are strictly less than `t - 3000`.
- Do not remove from the back: the oldest request is always at the front.

## What I Learned

- A queue is ideal when data expires in the same order it arrived.
- Although one `ping` can remove many requests, each request is removed only once, giving O(1) amortized time.

## Interview Takeaways

- Ask whether timestamps are sorted; this property enables the queue solution.
- Explain FIFO: the oldest timestamp leaves first.
- Distinguish worst-case work in one call from amortized complexity across all calls.

## Similar Problems

- Moving Average from Data Stream
- Dota2 Senate
- Design Hit Counter
