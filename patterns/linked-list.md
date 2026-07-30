# Linked List

## When to Use

- In-place reversal
- Cycle detection (Floyd's algorithm)
- Merge sorted lists
- Dummy head node simplifies edge cases

## Template (Reverse)

```java
ListNode prev = null, curr = head;
while (curr != null) {
    ListNode next = curr.next;
    curr.next = prev;
    prev = curr;
    curr = next;
}
return prev;
```

## Common Problems

- Reverse Linked List
- Merge Two Sorted Lists
- Linked List Cycle
- Reorder List
