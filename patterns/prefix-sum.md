# Prefix Sum

## When to Use

- Many range-sum queries on an array that does not change.
- Subarray sums, counts, or other cumulative values.

## Template

```java
int[] prefixSum = new int[nums.length + 1];
for (int i = 0; i < nums.length; i++) {
    prefixSum[i + 1] = prefixSum[i] + nums[i];
}

int rangeSum = prefixSum[right + 1] - prefixSum[left];
```

## Common Problems

- Range Sum Query — Immutable
- Subarray Sum Equals K
- Range Sum Query 2D — Immutable

## Pitfalls

- Use an array of length `n + 1` to handle ranges starting at index `0` cleanly.
- For inclusive ranges, subtract `prefixSum[left]` from `prefixSum[right + 1]`.
- If values can produce large totals, use `long` or `long long`.
