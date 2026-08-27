# Min Stack

Difficulty:
Medium

Date:
2026-08-27

Week:
5

Time Taken:
__ min

## Pattern

Stack, Auxiliary Min-Tracking

## Complexity

| Approach                                          | Time (per op) | Space |
|--------------------------------------------------|---------------|-------|
| Recompute min by scanning on every getMin()         | O(1) push/pop, O(n) getMin | O(n)  |
| Parallel min-stack, always push                     | O(1) all ops  | O(n)  |
| Parallel min-stack, push only on new min/tie         | O(1) all ops  | O(n) worst case, less in practice |

## Approach

1. Keep a second stack (`minStack`) synchronized with the main stack.
2. Every push also pushes the minimum "as of this point" onto `minStack`.
3. Every pop removes from both, so the top of `minStack` is always correct for whatever's currently in the main stack.
4. `getMin()` is then just `minStack.peek()` — no scanning ever needed.

## Mistakes I Made

- Trying to track the minimum with a single variable instead of a full parallel stack — this breaks the moment the current minimum gets popped, because there's no way to recover the previous minimum without rescanning.
- Forgetting to keep `pop()` popping both stacks together — desynchronizing them silently corrupts future `getMin()` calls.

## What I Learned

- Whenever a stack-based design needs an aggregate value (min, max, sum) that must survive pops correctly, a synchronized auxiliary stack recording "the aggregate as of this depth" is the standard technique — it turns an O(n) query into O(1) by paying a constant amount of extra bookkeeping on every push.
- This is a more general instance of the "each stack frame remembers everything it needs to restore state on pop" idea — same principle behind undo stacks and recursive backtracking's implicit call stack.

## Interview Takeaways

- Explain explicitly why a single "current min" variable is insufficient — it can't be un-done cleanly when popped.
- State the invariant: after any sequence of pushes/pops, `minStack.peek()` always equals the minimum of everything currently in `stack`.
- Mention the space-optimized variant (only push to `minStack` when the new value is `<=` current min) as a natural follow-up, along with the trade-off of needing `<=` (not `<`) to handle duplicate minimums correctly when popping.

## Similar Problems

- Max Stack
- Sliding Window Maximum
- Design a stack with increment operation
