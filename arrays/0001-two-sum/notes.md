# Two Sum

Difficulty:
Easy

Date:
2026-07-30

Week:
1

Time Taken:
25 min

## Pattern

Hash Map

## Complexity

| Approach    | Time  | Space |
|-------------|-------|-------|
| Brute Force | O(n²) | O(1)  |
| Optimal     | O(n)  | O(n)  |

## Approach

1. Iterate through the array once.
2. For each element, compute `complement = target - nums[i]`.
3. If complement exists in the hash map, return both indices.
4. Otherwise, store `nums[i] → i` in the map.

## Mistakes I Made

- Initially tried nested loops before recognizing the complement lookup pattern.
- Almost returned values instead of indices.

## What I Learned

- Hash map gives O(1) lookup — trade space for time.
- Store index on insert, check complement before insert (avoids using same element twice).

## Interview Takeaways

- State brute force first: "I can check every pair in O(n²)."
- Then optimize: "If I've seen the complement before, I have my answer."
- Always confirm: return indices, not values; exactly one solution exists.

## Similar Problems

- Two Sum II (sorted array → two pointers)
- Three Sum
- Four Sum
