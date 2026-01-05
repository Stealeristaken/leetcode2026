# Day 005 - Maximum Matrix Sum

**Date:** January 5, 2026  
**LeetCode #:** 1975  
**Difficulty:** Medium  
**Link:** [Maximum Matrix Sum](https://leetcode.com/problems/maximum-matrix-sum/)

---

## Problem Description

You are given an `n x n` integer `matrix`. You can do the following operation any number of times:

- Choose any two **adjacent** elements of `matrix` and **multiply each of them by -1**.

Two elements are considered adjacent if and only if they share a **border**.

Your goal is to **maximize** the sum of the matrix's elements. Return the maximum sum of the matrix's elements using the operation above.

### Example 1:
```
Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow these steps to reach sum = 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
```

### Example 2:
```
Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow this step to reach sum = 16:
- Multiply the 2 last elements in the second row by -1.
```

---

## Solution Approach

### Method: Greedy with Parity Observation

The key insight is that we can **move** a negative sign anywhere in the matrix by repeatedly applying the operation. This means:

1. **If we have an even number of negatives:** We can make all values positive
2. **If we have an odd number of negatives:** We must leave exactly one negative

### Algorithm:

1. Calculate the sum of **absolute values** of all elements
2. Count the number of negative elements
3. Track the **minimum absolute value** in the matrix
4. If negative count is odd: subtract `2 × minAbsVal` from the sum
   - Why 2×? Because we added it as positive but it should be negative

### Why This Works:

We can "push" negative signs around the matrix freely. With an even count, negatives can pair up and cancel. With an odd count, one negative must remain—optimally on the smallest absolute value.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n²) | Single pass through the n×n matrix |
| **Space** | O(1) | Only using constant extra variables |

Where `n` is the dimension of the square matrix.

---

## Key Takeaways

- Recognize that adjacent operations allow "moving" negatives freely
- Parity of negative count determines the outcome
- Greedy choice: if one negative must remain, put it on the smallest value
- Mathematical insight reduces a complex operation to simple counting

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation

