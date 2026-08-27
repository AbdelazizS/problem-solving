# Best Time to Buy and Sell Stock

Difficulty:
Easy

Date:
2026-08-27

Week:
5

Time Taken:
__ min

## Pattern

Sliding Window, Variable (Min-Tracking)

## Complexity

| Approach                                   | Time   | Space |
|-----------------------------------------------|--------|-------|
| Brute force: check every buy/sell pair          | O(n^2) | O(1)  |
| Single pass, track running minimum              | O(n)   | O(1)  |

## Approach

1. Initialize `minPrice` to infinity and `maxProfit` to 0.
2. Scan prices left to right; at each day, first update `minPrice` if the current price is lower.
3. Then compute the profit from selling today at the best `minPrice` seen so far, and keep the running maximum.
4. Return the accumulated `maxProfit`.

## Mistakes I Made

- Updating `maxProfit` before updating `minPrice` on the same day — order matters only if you'd want to disallow buying and selling same-day, but since selling the same day yields 0 profit anyway it's harmless here; still worth being deliberate about the order.
- Initially reaching for a brute-force nested loop (all pairs) before recognizing that only the running minimum "so far" ever matters for a given sell day.

## What I Learned

- This is really a single-pass "track the best base value seen so far, compare against it" pattern — a degenerate/implicit sliding window where the window's left edge is always the historical minimum rather than an explicit pointer.
- The key reframing: instead of asking "which pair (buy day, sell day) is best," ask "for each possible sell day, what's the best possible buy day before it" — this collapses to O(n) because "best buy day before i" only needs the running minimum, not a fresh scan.

## Interview Takeaways

- Explicitly state the reframing from "check all pairs" to "for each day, what's the best profit if I sell today" — this is the core insight that unlocks O(n).
- Clarify the problem constraint (single transaction, must buy before sell) up front, since this differs from Best Time to Buy and Sell Stock II (multiple transactions allowed).
- Mention that this is a variation of Kadane's algorithm framing — tracking a running best alongside a running reference point.

## Similar Problems

- Best Time to Buy and Sell Stock II
- Maximum Subarray (Kadane's Algorithm)
- Best Time to Buy and Sell Stock with Cooldown
