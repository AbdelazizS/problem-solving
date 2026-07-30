# Two Pointers

## When to Use

- Sorted arrays — find pairs, triplets
- In-place array modifications
- Palindrome checks
- Removing duplicates

## Variants

### Opposite Ends
```java
int left = 0, right = arr.length - 1;
while (left < right) {
    // move left or right based on condition
}
```

### Same Direction (Fast/Slow)
```java
int slow = 0;
for (int fast = 0; fast < arr.length; fast++) {
    // slow tracks write position
}
```

## Common Problems

- Valid Palindrome
- Remove Duplicates from Sorted Array
- Container With Most Water
- 3Sum
