# Day 045 - Champagne Tower

**Date:** February 14, 2026  
**LeetCode #:** 799  
**Difficulty:** Medium  
**Link:** [Champagne Tower](https://leetcode.com/problems/champagne-tower/)

---

## Problem Description

We stack glasses in a pyramid, where the first row has `1` glass, the second row has `2` glasses, and so on until the 100th row. Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top. When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it. When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.

Now after pouring `poured` cups of champagne, return how full the `query_glass`-th glass in the `query_row`-th row is (both 0-indexed).

### Example 1:
```
Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup into glass (0, 0) which is full. No overflow.
```

### Example 2:
```
Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: The excess 1 cup from (0,0) splits equally to (1,0) and (1,1).
```

---

## Solution Approach

### Method: Simulation with Dynamic Programming

The algorithm simulates the champagne flow through the pyramid:

1. **Initialize:** Create a 2D array to track champagne in each glass
   - Start with all `poured` champagne in the top glass `result[0][0]`

2. **Simulate Flow:** For each row from top to bottom:
   - For each glass that has more than 1 cup (overflow):
     - Calculate excess: `(result[i][j] - 1) / 2`
     - Distribute equally to left child `result[i+1][j]` and right child `result[i+1][j+1]`
     - Cap current glass at 1.0

3. **Return:** The amount in `result[query_row][query_glass]`

### Time Complexity
- **O(n²)** - Where n = 100 (max rows), iterating through the pyramid

### Space Complexity
- **O(n²)** - 2D array storing champagne amounts
