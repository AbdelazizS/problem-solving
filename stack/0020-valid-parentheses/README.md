# Valid Parentheses

| Field      | Value     |
|------------|-----------|
| Pattern    | Stack, LIFO Matching |
| Difficulty | Easy      |
| Time       | O(n)      |
| Space      | O(n)      |
| Status     | Solved    |
| LeetCode   | [#20](https://leetcode.com/problems/valid-parentheses/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given a string containing only `()[]{}`, determine whether every opening bracket has a matching closing bracket of the same type, closed in the correct order.

## Key Insight

The most recently opened bracket must be the next one closed — that's a Last-In-First-Out relationship, which is exactly what a stack models. Push opening brackets; on a closing bracket, it must match the top of the stack.

## Approach

1. Push any opening bracket onto the stack.
2. On a closing bracket, fail immediately if the stack is empty (nothing to match).
3. Pop the stack and check the popped bracket is the matching opening type; fail if not.
4. After scanning the whole string, the stack must be empty (no unmatched opens remain).

## Edge Cases

- Empty string is valid (vacuously — nothing unmatched).
- A closing bracket with an empty stack is invalid.
- Leftover unmatched opening brackets at the end (stack not empty) is invalid.
- Correct bracket types but wrong order, e.g. `"([)]"`, must be rejected.
