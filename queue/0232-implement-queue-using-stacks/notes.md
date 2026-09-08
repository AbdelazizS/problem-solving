# Implement Queue using Stacks

Difficulty:
Easy

Date:
2026-09-08

Week:
6

Time Taken:
__ min

## Pattern

Queue, Two-Stack Simulation

## Complexity

| Approach                                          | Time (per op)          | Space |
|--------------------------------------------------|--------------------------|-------|
| Single stack, reverse on every pop                   | O(n) pop, O(1) push        | O(n)  |
| Two stacks, lazy transfer (this solution)             | O(1) amortized all ops     | O(n)  |

## Approach

1. Two stacks: `inStack` absorbs pushes; `outStack` serves pops/peeks.
2. `push` is always a plain stack push onto `inStack` — cheap, no reordering.
3. Before a `pop`/`peek`, if `outStack` is empty, drain all of `inStack` into it — this reversal is exactly what converts LIFO order into FIFO order.
4. Once `outStack` has elements, keep serving from it directly until it's empty again, at which point the next drain happens.

## Mistakes I Made

- Transferring `inStack` to `outStack` on *every* pop call instead of only when `outStack` is empty — this is still correct, but destroys the amortized O(1) guarantee, degrading to O(n) per pop in the worst case (e.g., alternating push/pop).
- Forgetting that the transfer must move ALL of `inStack`, not just one element — moving fewer would put an older element underneath a newer one still sitting in `inStack`, breaking FIFO order later.

## What I Learned

- The core trick — reversing a stack's order onto a second stack — is what "un-does" the LIFO nature of a single stack to simulate FIFO.
- The lazy/amortized transfer (only refill `outStack` when it's empty) is the difference between a naive O(n)-per-op solution and an O(1)-amortized one; it's the same "pay once per element, total cost bounded" argument as many two-pointer and sliding-window analyses.

## Interview Takeaways

- Justify the amortized complexity explicitly: each element crosses from `inStack` to `outStack` exactly once in its lifetime, so across any sequence of n operations, total transfer work is O(n), giving O(1) amortized per operation.
- State the invariant: `outStack`'s top is always the oldest element among everything currently in the queue, whenever `outStack` is non-empty.
- Mention the mirror-image problem (Implement Stack using Queues) as a related exercise testing the same "convert between LIFO and FIFO" thinking in reverse.

## Similar Problems

- Implement Stack using Queues
- Design Circular Queue
- Min Stack
