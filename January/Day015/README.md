# Day 015 - Maximize Area of Square Hole in Grid

**Date:** January 15, 2026  
**LeetCode #:** 2943  
**Difficulty:** Medium  
**Link:** [Maximize Area of Square Hole in Grid](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/)

---

## Problem Description

You are given the two integers `n` and `m` and two integer arrays `hBars` and `vBars`.

The grid has `n + 2` horizontal bars and `m + 2` vertical bars. You can remove some bars from `hBars` and `vBars` to maximize the area of a square hole.

Return the **maximum area** of a square-shaped hole in the grid after removing some (possibly none) of the bars.

### Example 1:
```
Input: n = 2, m = 1, hBars = [2,3], vBars = [2]
Output: 4
Explanation: Remove horizontal bar 2 and 3, and vertical bar 2.
This creates a 2×2 square hole.
```

### Example 2:
```
Input: n = 1, m = 1, hBars = [2], vBars = [2]
Output: 4
Explanation: Remove both bars to create a 2×2 hole.
```

---

## Solution Approach

### Method: Find Longest Consecutive Sequence

The key insight: removing consecutive bars creates the largest gaps.

### Algorithm:

1. **Sort both bar arrays** (hBars and vBars)

2. **Find longest consecutive sequence in each:**
   - Iterate through sorted bars
   - If current bar = previous + 1: extend streak
   - Otherwise: reset streak to 2 (minimum gap is 2 with one bar removed)

3. **Square side = min(maxHorizontal, maxVertical)**
   - The hole must be square, so limited by smaller dimension

4. **Return side²**

### Why Start Count at 2?

When you remove a bar, you create a gap of size 2 (one unit on each side). Removing consecutive bars extends this gap.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(h log h + v log v) | Sorting both arrays |
| **Space** | O(1) | Only using constant extra variables |

Where `h` and `v` are lengths of hBars and vBars.

---

## Key Takeaways

- Problem reduces to finding longest consecutive subsequence
- Sort first, then linear scan for consecutive elements
- Square constraint means take minimum of both dimensions
- Greedy approach: consecutive removals maximize gap

---

## Files

- [solution.cpp](solutipn.cpp) - C++ implementation
