# Course Schedule

| Field      | Value     |
|------------|-----------|
| Pattern    | Graph, Topological Sort (Kahn's Algorithm) |
| Difficulty | Medium    |
| Time       | O(V + E)  |
| Space      | O(V + E)  |
| Status     | Solved    |
| LeetCode   | [#207](https://leetcode.com/problems/course-schedule/) |

## Solutions

- [Java](java/Solution.java)
- [C++](cpp/Solution.cpp)

## Summary

Given `numCourses` and a list of prerequisite pairs `[a, b]` (meaning course `b` must be taken before course `a`), determine whether it's possible to finish all courses.

## Key Insight

Modeling courses as a directed graph (edge `b -> a` for prerequisite pair `[a, b]`), finishing all courses is possible exactly when the graph has no cycle. A course with zero remaining prerequisites (in-degree 0) can always be taken next; repeatedly "taking" such courses and removing their outgoing edges (decrementing neighbors' in-degrees) processes every course in a valid order if and only if no cycle exists — this is Kahn's algorithm for topological sorting.

## Approach

1. Build an adjacency list (`prereq -> [courses that depend on it]`) and an `inDegree` array counting each course's remaining prerequisites.
2. Seed a queue with every course that has `inDegree == 0` (no prerequisites, can be taken immediately).
3. Repeatedly dequeue a course, count it as "taken," and decrement the in-degree of every course that depends on it — enqueueing any that drop to 0.
4. If the total count of courses processed equals `numCourses`, every course was eventually reachable with no unresolved dependency — return true. Otherwise, a cycle exists (some courses never reach in-degree 0), return false.

## Edge Cases

- No prerequisites at all → every course starts at in-degree 0, trivially finishable.
- A direct cycle (`a` requires `b`, `b` requires `a`) → both stay at in-degree > 0 forever, never enqueued, count falls short.
- A self-loop (`a` requires `a`) → same idea, `a` never reaches in-degree 0.
- Disconnected groups of courses are handled naturally since the queue is seeded with *all* zero-in-degree courses across the whole graph, not just one connected component.
