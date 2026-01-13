# Day 013 - Separate Squares I

**Date:** January 13, 2026  
**LeetCode #:** 3453  
**Difficulty:** Medium  
**Link:** [Separate Squares I](https://leetcode.com/problems/separate-squares-i/)

---

## Problem Description

You are given a 2D integer array `squares` where `squares[i] = [xi, yi, li]` represents the coordinates of the bottom-left point and the side length of the i-th square.

Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

Answers within `10^-5` of the actual answer will be accepted.

### Example 1:
```
Input: squares = [[0,0,1],[2,2,1]]
Output: 1.0
Explanation: The line y = 1 splits the plane into:
- Above: Area = 1 (from second square)
- Below: Area = 1 (from first square)
```

### Example 2:
```
Input: squares = [[0,0,2],[1,1,1]]
Output: 1.0
Explanation: The line y = 1 divides the total area equally.
```

---

## Solution Approach

### Method: Line Sweep with Difference Array

Use coordinate compression and a difference array to track how the "active width" changes at each y-coordinate.

### Algorithm:

1. **Calculate total area** of all squares
2. **Build difference array:**
   - At y = bottom of square: add side length to active width
   - At y = top of square: subtract side length from active width

3. **Sweep from bottom to top:**
   - For each y-segment, accumulate area = width × height
   - When accumulated area ≥ half of total area, we found our target region

4. **Calculate exact y-coordinate:**
   - Use linear interpolation to find the precise y where area splits equally

### Key Insight:

The accumulated area grows linearly within each segment (between consecutive y-coordinates), allowing us to calculate the exact split point.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n log n) | Sorting the y-coordinates |
| **Space** | O(n) | Difference array storage |

Where `n` is the number of squares.

---

## Key Takeaways

- Line sweep technique for 2D geometric problems
- Difference array efficiently tracks cumulative changes
- Linear interpolation for finding exact split point
- `itertools.pairwise` for iterating consecutive elements

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation
