# Dynamic Programming

## When to Use

- Optimal substructure + overlapping subproblems
- Count ways, min/max cost, yes/no feasibility

## Approaches

1. **Top-down (memoization)** — recursive + cache
2. **Bottom-up (tabulation)** — fill dp table iteratively

## Template

```java
int[] dp = new int[n + 1];
dp[0] = baseCase;
for (int i = 1; i <= n; i++) {
    dp[i] = /* transition from dp[i-1], dp[i-2], etc. */;
}
return dp[n];
```

## Common Problems

- Climbing Stairs
- House Robber
- Coin Change
- Longest Increasing Subsequence
- Edit Distance

## Pitfalls

- Wrong state definition
- Off-by-one in indices
- Not handling base cases
