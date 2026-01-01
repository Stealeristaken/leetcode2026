# Day 001 - Plus One

**Date:** January 1, 2026  
**LeetCode #:** 66  
**Difficulty:** Easy  
**Link:** [Plus One](https://leetcode.com/problems/plus-one/)

---

## Problem Description

You are given a **large integer** represented as an integer array `digits`, where each `digits[i]` is the i-th digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

### Example 1:
```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
```

### Example 2:
```
Input: digits = [9,9,9]
Output: [1,0,0,0]
Explanation: The array represents the integer 999.
Incrementing by one gives 999 + 1 = 1000.
```

---

## Solution Approach

### Method: Right-to-Left Traversal with Carry Handling

The algorithm traverses the array from the **rightmost digit (least significant)** to the left:

1. **If current digit < 9:** Simply increment it and return immediately (no carry needed)
2. **If current digit = 9:** Set it to 0 and continue to the next digit (carry propagates)
3. **If all digits were 9:** Insert 1 at the beginning (e.g., 999 → 1000)

### Why This Works:
- We only need to propagate carry when a digit is 9
- Early return optimization: stop as soon as no carry is needed
- Edge case handled: when all digits are 9, the result has one more digit

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | Single pass through the array in worst case (all 9s) |
| **Space** | O(1) | In-place modification, only O(n) if new digit is inserted |

Where `n` is the number of digits in the input array.

---

## Key Takeaways

- Handle carry propagation efficiently with early termination
- Edge case: all 9s require array expansion
- In-place modification saves space

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
