# Binary Tree Level Order Traversal

Difficulty:
Medium

Date:
2026-08-28

Week:
5

Time Taken:
__ min

## Pattern

Tree, BFS (Level Order)

## Complexity

| Approach                                  | Time | Space |
|----------------------------------------------|------|-------|
| BFS with queue, size-snapshot per level         | O(n) | O(n)  |
| DFS with depth parameter, append to result[depth] | O(n) | O(n)  |

## Approach

1. Queue starts with just the root.
2. At the top of each while-loop iteration, snapshot `queue.size()` — this is the exact count of nodes belonging to the current level.
3. Dequeue exactly that many nodes, recording their values and enqueueing their children.
4. Once that many dequeues are done, the current level list is complete; append it and move to the next iteration (which will now only see the next level's nodes, since size was captured before their children were added).

## Mistakes I Made

- Forgetting to snapshot `queue.size()` before the inner loop, and instead checking `!queue.isEmpty()` inside the loop — this mixes nodes from the next level into the current one, since children get enqueued mid-loop.
- Reaching for DFS with a depth parameter as the "obvious" solution before considering BFS is a more direct match for the problem, since a queue's processing order already matches level order.

## What I Learned

- The "snapshot the size, then loop that many times" idiom is the standard way to convert a plain BFS traversal into a level-aware one — it's a small but essential addition over vanilla BFS.
- Both BFS (queue) and DFS (recursion with a depth index into the result array) can solve level-order problems; BFS is more natural/directly readable here since the queue's FIFO order already matches level order without extra bookkeeping.

## Interview Takeaways

- Explain the size-snapshot trick explicitly — it's the one non-obvious detail that turns generic BFS into level-order BFS.
- Mention the DFS alternative (pass current depth, append to `result.get(depth)`, creating a new list if needed) as a valid alternative approach, useful if asked to avoid extra queue space.
- Note this pattern generalizes directly to zigzag level order, right-side view, and level-average problems — all just minor tweaks to the same BFS skeleton.

## Similar Problems

- Binary Tree Zigzag Level Order Traversal
- Binary Tree Right Side View
- Average of Levels in Binary Tree
- Minimum Depth of Binary Tree (BFS variant)
