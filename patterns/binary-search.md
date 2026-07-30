# Binary Search

## When to Use

- Sorted array search
- Search space can be halved (answer space, not just array indices)

## Template

```java
int left = 0, right = nums.length - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
```

## Common Problems

- Binary Search
- Search Insert Position
- Find Minimum in Rotated Sorted Array
- Koko Eating Bananas
