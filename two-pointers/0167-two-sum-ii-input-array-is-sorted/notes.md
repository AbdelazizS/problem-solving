# Two Sum II - Input Array Is Sorted

Difficulty:
Medium

Date:
2026-08-27

Week:
5

Time Taken:
__ min

## Pattern

Two Pointers, Opposite Ends (Sorted Search)

## Complexity

| Approach                                | Time         | Space |
|--------------------------------------------|--------------|-------|
| Hash map (ignores sortedness)               | O(n)         | O(n)  |
| Two pointers, opposite ends                 | O(n)         | O(1)  |
| Binary search for complement per element    | O(n log n)   | O(1)  |

## Approach

1. `left` and `right` start at the two ends of the sorted array.
2. Compare `numbers[left] + numbers[right]` against `target`.
3. Sum too small → the only lever to increase it without revisiting a pair is moving `left` forward (skips the smallest candidate).
4. Sum too large → move `right` backward (skips the largest candidate).
5. Sum matches → done, return 1-indexed positions.

## Mistakes I Made

- Defaulting to the hash-map solution from Two Sum I out of habit, missing that sortedness is a free optimization opportunity here — using it drops space from O(n) to O(1).
- Forgetting the problem wants 1-indexed output, not the raw 0-indexed loop variables.

## What I Learned

- Sortedness is itself a strong signal for two pointers over hashing — whenever comparing a combined value (sum, difference, product) against a target in a sorted array, moving pointers based on whether the value is too high or too low is a direct, provably-correct search strategy.
- This is a good contrast case against Two Sum I: same problem shape, but the extra "sorted" constraint changes the optimal pattern entirely.

## Interview Takeaways

- Justify why advancing `left` (not `right`) is correct when the sum is too small: only increasing the smaller-magnitude side of the pair can increase the sum without ever revisiting a pair already ruled out.
- Note the O(1) space win over the hash-map approach as the direct payoff of exploiting the sorted property.
- Mention this generalizes to 3Sum/4Sum, where one value is fixed and the remaining sorted subarray is searched with the same two-pointer technique.

## Similar Problems

- Two Sum
- 3Sum
- 4Sum
- Container With Most Water
