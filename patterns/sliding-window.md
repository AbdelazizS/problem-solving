# Sliding Window

## When to Use

- Subarray/substring with a constraint (sum, distinct chars, etc.)
- Fixed or variable window size

## Template

```java
int left = 0;
for (int right = 0; right < s.length(); right++) {
    // expand window: add s.charAt(right)

    while (/* window invalid */) {
        // shrink: remove s.charAt(left)
        left++;
    }

    // update answer with valid window
}
```

## Common Problems

- Best Time to Buy and Sell Stock
- Longest Substring Without Repeating Characters
- Minimum Window Substring
- Max Consecutive Ones III
