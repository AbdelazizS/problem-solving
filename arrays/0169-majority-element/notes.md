# Majority Element

Difficulty:
Easy

Date:
2026-08-05

Week:
1

Time Taken:
__ min

## Pattern

Boyer-Moore Voting

## Complexity

| Approach           | Time | Space |
|--------------------|------|-------|
| Hash map frequency | O(n) | O(n)  |
| Boyer-Moore Voting | O(n) | O(1)  |

## Approach

1. Keep a `candidate` and a `count`, both initially empty or zero.
2. When `count` is zero, choose the current number as the new candidate.
3. Increment `count` when the current number equals the candidate; otherwise decrement it.
4. Return the final candidate, which is guaranteed to be the majority element.

## Mistakes I Made

- Do not use Boyer-Moore without confirming that a majority element is guaranteed.
- Reset the candidate only when the count reaches zero.

## What I Learned

- Pairwise cancellation can reduce a frequency problem to constant space.
- The majority condition, more than `n / 2` occurrences, is what makes the final candidate correct.

## Interview Takeaways

- Start by describing the hash-map frequency-counting approach.
- Improve to Boyer-Moore when the problem guarantees a majority element.
- If no majority is guaranteed, verify the final candidate with a second pass.

## Similar Problems

- Majority Element II
- Find the Difference
- Single Number
