# Day 011 - Maximal Rectangle

**Date:** January 11, 2026  
**LeetCode #:** 85  
**Difficulty:** Hard  
**Link:** [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

---

## Problem Description

Given a `rows x cols` binary matrix filled with `'0'`s and `'1'`s, find the largest rectangle containing only `'1'`s and return its area.

### Example 1:
```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture (3x2 = 6).
```

### Example 2:
```
Input: matrix = [["0"]]
Output: 0
```

### Example 3:
```
Input: matrix = [["1"]]
Output: 1
```

---

## Solution Approach

### Method: Histogram + Monotonic Stack

Transform the 2D problem into multiple 1D "Largest Rectangle in Histogram" problems.

### Algorithm:

1. **Build histogram row by row:**
   - For each cell, if `'1'`: increment height from previous row
   - If `'0'`: reset height to 0

2. **For each row's histogram, find largest rectangle using monotonic stack:**
   - Maintain stack of indices with increasing heights
   - When a smaller height is encountered, pop and calculate area
   - Width = current index - stack top - 1

3. **Track maximum area across all rows**

### Why Monotonic Stack?

- Efficiently finds the first smaller element on both sides
- Each bar is pushed and popped exactly once → O(n) per row

### Sentinel Trick:
- Add extra column with height 0 to force final calculations
- Avoids special handling for remaining elements in stack

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(m × n) | Process each cell once, stack ops are amortized O(1) |
| **Space** | O(n) | Heights array and stack |

Where `m` is rows and `n` is columns.

---

## Key Takeaways

- Reduce 2D problem to 1D histogram problem
- Monotonic stack is powerful for "nearest smaller element" queries
- Sentinel values simplify edge case handling
- Classic combination of two algorithmic techniques

---

## Files

- [solution.py](solution.py) - Python implementation
