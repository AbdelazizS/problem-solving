# Best Time to Buy and Sell Stock

| Field      | Value     |
|------------|-----------|
| Pattern    | Sliding Window, Variable (Min-Tracking) |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(1)      |
| Status     | Solved    |
| LeetCode   | [#121](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given an array `prices` where `prices[i]` is the stock price on day `i`, find the maximum profit achievable by buying on one day and selling on a later day. Return 0 if no profit is possible.

## Key Insight

The best sell day's profit only depends on the lowest price seen *before* it. Rather than checking every buy/sell pair, track the minimum price seen so far while scanning forward — at each day, the best possible profit if selling today is `price - minSoFar`, and the answer is the max of that value across the whole scan.

## Approach

1. Track `minPrice` (lowest price seen so far) and `maxProfit` (best profit found so far).
2. For each price in order: update `minPrice` to be the smaller of itself and the current price.
3. Update `maxProfit` to be the larger of itself and `price - minPrice` (the profit if selling today, having bought at the cheapest point so far).
4. Return `maxProfit` after the scan.

## Edge Cases

- Prices strictly decreasing → no profitable trade exists, answer is 0 (never negative).
- Single price → no valid sell day, answer is 0.
- Prices strictly increasing → best trade is buy on day 0, sell on the last day.
- Buying and selling on the same day is implicitly disallowed by requiring a later day, though the algorithm handles it naturally since `price - minPrice` is 0 the moment a new minimum is set.
