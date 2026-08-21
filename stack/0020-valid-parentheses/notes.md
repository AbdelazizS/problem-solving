# Valid Parentheses

Difficulty:
Easy

Date:
2026-08-21

Week:
3

Time Taken:
__ min

## Pattern

Stack, LIFO Matching

## Complexity

| Approach                          | Time | Space |
|------------------------------------|------|-------|
| Stack of expected closers          | O(n) | O(n)  |

## Approach

1. Scan the string left to right.
2. Push opening brackets onto a stack.
3. On a closing bracket, pop and check it matches the corresponding opening type; empty stack on a close = invalid.
4. After the scan, valid only if the stack is empty.

## Mistakes I Made

- Forgetting to check `stack.isEmpty()` before popping on a closing bracket causes an exception/underflow.
- Forgetting the final "stack must be empty" check misses strings with unmatched trailing opens like `"((("`.

## What I Learned

- Any "most recent thing must be resolved first" relationship is a signal for a stack (LIFO), same way FIFO ordering signaled a queue in [Number of Recent Calls](../../queue/0933-number-of-recent-calls/).
- A `Deque` (ArrayDeque) is the idiomatic Java stack; `stack<char>` (`<stack>`) covers it directly in C++.

## Interview Takeaways

- State the invariant: at any point, the stack holds exactly the still-unmatched opening brackets in order.
- Explain both failure modes: closing bracket with nothing to match (stack empty), and leftover opens at the end (stack non-empty).
- Mention this pattern generalizes to any nested/balanced structure check (e.g. HTML tag validation, expression parsing).

## Similar Problems

- Min Stack
- Generate Parentheses
- Remove Invalid Parentheses
- Basic Calculator
