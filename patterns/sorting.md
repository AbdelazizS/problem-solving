# Sorting

## When to Use

- The original element order does not matter.
- Duplicates, nearby values, or overlapping ranges become easier to detect in order.
- Sorting enables a two-pointer scan or interval merge.

## Template

```java
Arrays.sort(nums);

int left = 0;
int right = nums.length - 1;
while (left < right) {
    // compare nums[left] and nums[right]
}
```

## Common Problems

- Intersection of Two Arrays
- 3Sum
- Merge Intervals
- Contains Duplicate

## Pitfalls

- Sorting usually changes the input array.
- Include the sorting cost in the time complexity.
- Define how duplicates should be handled after sorting.
