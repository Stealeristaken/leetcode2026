# Day 018 - Largest Magic Square

**Date:** January 18, 2026  
**LeetCode #:** 1895  
**Difficulty:** Medium  
**Link:** [Largest Magic Square](https://leetcode.com/problems/largest-magic-square/)

---

## Problem Description

A `k x k` **magic square** is a grid where the sum of every row, every column, and both diagonals are all equal.

Given an `m x n` grid of integers, return the **largest** magic square that can be found within this grid.

### Example 1:
```
Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has size 3×3 with magic sum = 12.
```

### Example 2:
```
Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2
```

---

## Solution Approach

### Method: Prefix Sums + Brute Force Check

Use prefix sums for efficient row/column sum queries, then check all possible squares.

### Algorithm:

1. **Build prefix sums:**
   - `row[i][j]`: sum of row i from column 0 to j-1
   - `col[i][j]`: sum of column j from row 0 to i-1

2. **Check from largest to smallest k:**
   - For each top-left corner (r, c)
   - Verify if k×k square starting at (r, c) is magic

3. **Magic square validation:**
   - All rows have same sum (use row prefix)
   - All columns have same sum (use col prefix)
   - Both diagonals have same sum (compute directly)
   - All sums equal the target

4. **Return first valid k** (checking largest first)

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(m × n × min(m,n)²) | For each cell, check all square sizes |
| **Space** | O(m × n) | Prefix sum arrays |

Where `m` and `n` are grid dimensions.

---

## Key Takeaways

- Prefix sums enable O(1) row/column sum queries
- Check from largest k downward for early termination
- Diagonal sums still need O(k) computation
- Classic matrix prefix sum application

---

## Files

- [solution.py](solution.py) - Python implementation
