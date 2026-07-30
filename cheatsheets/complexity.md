# Complexity Cheat Sheet

## Common Complexities

| Notation   | Name         | Example                          |
|------------|--------------|----------------------------------|
| O(1)       | Constant     | Hash map lookup                  |
| O(log n)   | Logarithmic  | Binary search                    |
| O(n)       | Linear       | Single pass array scan           |
| O(n log n) | Linearithmic | Merge sort, heap sort            |
| O(n²)      | Quadratic    | Nested loops, brute force pairs  |
| O(2ⁿ)      | Exponential  | Subsets without memoization      |

## Space Complexity Rules

- Recursion depth adds O(h) stack space (tree height)
- Hash map storing n elements → O(n)
- In-place algorithms → O(1) extra space

## Interview Targets

| Difficulty | Expected Time Complexity |
|------------|--------------------------|
| Easy       | O(n) or O(n log n)       |
| Medium     | O(n log n) or O(n²) acceptable if optimized |
| Hard       | Often O(n log n) or clever O(n) |

## Amortized Analysis

- `ArrayList.add` — O(1) amortized (occasional resize)
- `HashMap` operations — O(1) average, O(n) worst case
