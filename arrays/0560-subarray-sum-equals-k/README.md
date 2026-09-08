# Subarray Sum Equals K

| Field      | Value     |
|------------|-----------|
| Pattern    | Prefix Sum + Hash Map |
| Difficulty | Medium    |
| Time       | O(n)      |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#560](https://leetcode.com/problems/subarray-sum-equals-k/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an integer array `nums` and an integer `k`, return the total number of contiguous subarrays whose elements sum to exactly `k`.

## Key Insight

The sum of any subarray `nums[i+1..j]` equals `prefixSum[j] - prefixSum[i]`. So a subarray ending at index `j` sums to `k` exactly when some earlier prefix sum equals `prefixSum[j] - k`. Instead of recomputing subarray sums for every pair `(i, j)` (O(n^2)), track how many times each prefix sum value has occurred so far in a hash map — then at each `j`, the count of valid starting points is just a O(1) lookup.

## Approach

1. Maintain a running `prefixSum` and a hash map `prefixCount` mapping "a prefix sum value" → "how many times it's occurred so far," seeded with `{0: 1}` (representing the empty prefix, needed so subarrays starting at index 0 are counted correctly).
2. For each number, add it to `prefixSum`.
3. Look up `prefixSum - k` in `prefixCount` — its stored count is exactly the number of previous prefixes that, combined with the current one, form a subarray summing to `k`. Add that to the running answer.
4. Record the current `prefixSum` in the map (incrementing its count) before moving to the next element.

## Edge Cases

- `k == 0` with zeros present → the `{0: 1}` seed and repeated-prefix-sum tracking correctly counts subarrays of zeros.
- Negative numbers are handled fine — prefix sums aren't required to be monotonic for this technique to work (unlike a sliding window, which needs non-negative numbers).
- No valid subarray exists → count stays 0.
- The seed `prefixCount = {0: 1}` is essential: without it, a subarray starting at index 0 that itself sums to exactly `k` (i.e. `prefixSum == k` at some point) would never be counted, since there'd be no matching "0" entry to look up.
