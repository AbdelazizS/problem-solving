# Common Mistakes

## General

- Not clarifying constraints (empty input, duplicates, negative numbers)
- Jumping to code before stating approach and complexity
- Forgetting edge cases: empty, single element, all same values

## Arrays / Strings

- Off-by-one errors in loops (`<=` vs `<`)
- Modifying array while iterating forward
- Not handling index out of bounds

## Hash Map

- Using `get()` instead of `getOrDefault()` and getting null
- Storing index when you need count (or vice versa)

## Two Pointers

- Moving wrong pointer when values are equal
- Not checking `left < right` in while condition

## Trees / Graphs

- Forgetting null checks on nodes
- Not marking visited nodes (infinite loops in graphs)
- Confusing DFS stack vs BFS queue

## Dynamic Programming

- Wrong base cases
- Using wrong dimension for dp array
- Not initializing dp[0] correctly

## Interview Habits

- **Do:** Think aloud, write pseudocode, test with example
- **Do:** State time/space complexity before and after optimization
- **Don't:** Go silent for long stretches
- **Don't:** Give up without trying brute force first
