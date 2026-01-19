# Day 019 - Maximum Side Length of a Square with Sum Less than or Equal to Threshold

**Date:** January 19, 2026  
**LeetCode #:** 1292  
**Difficulty:** Medium  
**Link:** [Maximum Side Length of a Square with Sum Less than or Equal to Threshold](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

---

## Problem Description

Given a `m x n` matrix `mat` and an integer `threshold`, return the maximum side-length of a square with a sum less than or equal to `threshold`, or return `0` if there is no such square.

### Example 1:
```
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of a square with sum ≤ 4 is 2.
```

### Example 2:
```
Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0
```

---

## Solution Approach

### Method: 2D Prefix Sum + Linear Search

Build prefix sums for O(1) submatrix sum queries, then find largest valid square.

### Algorithm:

1. **Build 2D prefix sum:**
   ```
   pre[i][j] = sum of all elements in submatrix (0,0) to (i-1, j-1)
   ```

2. **Square sum formula:**
   ```
   sum(r-k, c-k, r, c) = pre[r][c] - pre[r-k][c] - pre[r][c-k] + pre[r-k][c-k]
   ```

3. **Search for largest valid k:**
   - For each size k from 1 to min(m, n)
   - Check if any k×k square has sum ≤ threshold
   - Stop when no valid square found (optimization)

4. **Return** largest valid k

### Optimization:

If size k fails, larger sizes will also fail (monotonic property allows early termination).

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(m × n × min(m,n)) | Check all squares for each size |
| **Space** | O(m × n) | 2D prefix sum array |

Where `m` and `n` are matrix dimensions.

---

## Key Takeaways

- 2D prefix sum is essential for submatrix sum queries
- Inclusion-exclusion principle for rectangle sums
- Early termination when no valid square exists
- Could be optimized further with binary search on k

---

## Files

- [solution.py](solution.py) - Python implementation
