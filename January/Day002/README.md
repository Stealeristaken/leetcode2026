# Day 002 - N-Repeated Element in Size 2N Array

**Date:** January 2, 2026  
**LeetCode #:** 961  
**Difficulty:** Easy  
**Link:** [N-Repeated Element in Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)

---

## Problem Description

You are given an integer array `nums` with the following properties:

- `nums.length == 2 * n`
- `nums` contains `n + 1` **unique** elements
- Exactly one element of `nums` is repeated `n` times

Return the element that is repeated `n` times.

### Example 1:
```
Input: nums = [1,2,3,3]
Output: 3
```

### Example 2:
```
Input: nums = [2,1,2,5,3,2]
Output: 2
```

### Example 3:
```
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
```

---

## Solution Approach

### Method: Hash Set

The algorithm uses a hash set to track seen elements:

1. **Iterate through the array:** For each element, check if it's already in the set
2. **If found:** Return immediately - this is the repeated element
3. **If not found:** Add the element to the set

### Why This Works:
- Since only one element repeats and all others are unique, the first duplicate we encounter must be the answer
- Early return optimization: we find the answer as soon as we see the first repeat
- Time Complexity: O(n) - we traverse the array once
- Space Complexity: O(n) - for storing elements in the hash set

---

## Complexity Analysis

| Metric | Value |
|--------|-------|
| Time Complexity | O(n) |
| Space Complexity | O(n) |

---

## Key Takeaways

- Hash sets provide O(1) average lookup time
- When looking for duplicates, hash-based solutions are often optimal
- The problem guarantees exactly one repeated element, so we can return on first duplicate
