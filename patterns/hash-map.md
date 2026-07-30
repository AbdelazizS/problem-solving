# Hash Map

## When to Use

- Need O(1) lookup by value or key
- Counting frequencies
- Finding complements (Two Sum pattern)
- Detecting duplicates or anagrams

## Template (Java)

```java
Map<Integer, Integer> map = new HashMap<>();

for (int i = 0; i < nums.length; i++) {
    int complement = target - nums[i];
    if (map.containsKey(complement)) {
        return new int[] { map.get(complement), i };
    }
    map.put(nums[i], i);
}
```

## Common Problems

- Two Sum
- Valid Anagram
- Contains Duplicate
- Group Anagrams
- Top K Frequent Elements

## Pitfalls

- Forgetting to handle null/empty input
- Using wrong key type (Integer vs int boxing overhead is fine for interviews)
- Not considering order of insertion when order matters
