# Maximum Average Subarray I

Difficulty:
Easy

Date:
2026-08-09

Week:
2

Time Taken:
__ min

## Pattern

Fixed-Size Sliding Window

## Complexity

| Approach            | Time  | Space |
|---------------------|-------|-------|
| Recalculate each sum | O(nk) | O(1)  |
| Sliding window       | O(n)  | O(1)  |

## Approach

1. Calculate the sum of the first `k` elements.
2. Store it as the current maximum sum.
3. Slide the window one position at a time.
4. Add the new rightmost value and subtract the value leaving on the left.
5. Update the maximum sum, then divide it by `k` after the scan.

## Mistakes I Made

- Do not recalculate the sum of every window from scratch.
- Return a `double` so the average is not truncated by integer division.
- Keep the window size exactly `k`.

## What I Learned

- Fixed-size sliding windows reuse work from the previous window.
- Maximizing the sum is equivalent to maximizing the average when every window has the same size.

## Interview Takeaways

- Explain the brute-force O(nk) approach first.
- State that each number is added once and removed once, giving O(n) time.
- Use a wider numeric type for the running sum when constraints could overflow an integer.

## Similar Problems

- Maximum Sum Subarray of Size K
- Subarray Product Less Than K
- Maximum Sum of Distinct Subarrays With Length K
