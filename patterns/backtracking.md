# Backtracking

## When to Use

- Generate all combinations/permutations/subsets
- Constraint satisfaction (N-Queens, Sudoku)
- Explore all paths with pruning

## Template

```java
void backtrack(List<Integer> path, int start) {
    if (/* base case / valid solution */) {
        result.add(new ArrayList<>(path));
        return;
    }
    for (int i = start; i < n; i++) {
        path.add(candidates[i]);
        backtrack(path, i + 1);
        path.remove(path.size() - 1); // undo
    }
}
```

## Common Problems

- Subsets
- Combination Sum
- Permutations
- N-Queens
