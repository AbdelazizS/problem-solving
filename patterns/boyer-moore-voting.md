# Boyer-Moore Voting

## When to Use

- A value is guaranteed to occur more than half of the time.
- A majority candidate can be found by cancelling different values in pairs.

## Template

```java
int candidate = 0;
int count = 0;

for (int num : nums) {
    if (count == 0) {
        candidate = num;
    }
    count += num == candidate ? 1 : -1;
}

return candidate;
```

## Common Problems

- Majority Element
- Majority Element II

## Pitfall

If the problem does not guarantee a majority element, count the final candidate in a second pass to verify it.
