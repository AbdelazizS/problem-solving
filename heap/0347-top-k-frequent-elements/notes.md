# Top K Frequent Elements

Difficulty:
Medium

Date:
2026-09-07

Week:
6

Time Taken:
__ min

## Pattern

Hash Map + Heap, Top K

## Complexity

| Approach                                             | Time        | Space |
|---------------------------------------------------------|-------------|-------|
| Sort all distinct values by frequency                      | O(n log n)  | O(n)  |
| Hash map + min-heap capped at size k                        | O(n log k)  | O(n)  |
| Hash map + bucket sort by frequency                          | O(n)        | O(n)  |

## Approach

1. Count frequencies with a hash map — O(n).
2. Maintain a min-heap of (value, frequency) pairs, ordered by frequency, capped at size k.
3. Push every pair; whenever size exceeds k, pop the smallest-frequency pair.
4. The heap ends up holding exactly the k most frequent values; extract them into the result.

## Mistakes I Made

- Sorting all distinct values by frequency first (O(n log n)) as the default instinct, before recognizing that only the top k matter — a bounded min-heap avoids sorting everything.
- Ordering the heap comparator backwards (max-heap of size k, keeping the *smallest* frequencies) — the min-heap-capped-at-k pattern specifically needs a min-heap so the easiest-to-discard (lowest frequency) candidate is always on top.

## What I Learned

- Frequency-based "Top K" problems are a direct combination of two familiar patterns: hash map for counting, then the same bounded min-heap technique from Kth Largest Element in an Array — recognizing this composition is more valuable than memorizing this problem specifically.
- Because frequency is bounded by array length (can't exceed n), a bucket-sort approach (index = frequency, bucket contents = values with that frequency) achieves true O(n), better than the heap's O(n log k) — good to mention as a follow-up optimization even if the heap version is what's implemented first.

## Interview Takeaways

- Narrate the two-stage decomposition explicitly: "first I need counts, then I need the top k of those counts" — this shows the interviewer you're composing known patterns rather than searching for a new one.
- Justify the min-heap choice the same way as in Kth Largest: it lets you cheaply discard the *worst* of your k current candidates.
- Bring up the O(n) bucket-sort alternative if pushed for a further optimization, noting the trade-off is a less "obviously correct" data structure for a small constant-factor win.

## Similar Problems

- Kth Largest Element in an Array
- Sort Characters By Frequency
- K Closest Points to Origin
- Top K Frequent Words
