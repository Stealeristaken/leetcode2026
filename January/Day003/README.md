````markdown
# Day 003 - Number of Ways to Paint N × 3 Grid

**Date:** January 3, 2026  
**LeetCode #:** 1411  
**Difficulty:** Hard  
**Link:** [Number of Ways to Paint N × 3 Grid](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/)

---

## Problem Description

You have a `grid` of size `n x 3` and you want to paint each cell of the grid with exactly one of the three colors: **Red**, **Yellow**, or **Green** while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

You are given `n` the number of rows of the grid.

Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo `10^9 + 7`.

### Example 1:
```
Input: n = 1
Output: 12
Explanation: There are 12 possible ways to paint the grid.
```

### Example 2:
```
Input: n = 5000
Output: 30228214
```

---

## Solution Approach

### Method: Dynamic Programming with State Compression

The key insight is that for a 3-column grid, each row can only have two types of valid patterns:

1. **3-color pattern (ABC):** All three cells have different colors (e.g., Red-Yellow-Green)
   - Count: 6 ways (3! = 6 permutations)

2. **2-color pattern (ABA):** First and third cells have the same color, middle is different (e.g., Red-Yellow-Red)
   - Count: 6 ways (3 choices for outer × 2 choices for middle)

### Transition Rules:

When moving from row `i` to row `i+1`:

- **From 3-color (ABC) to next row:**
  - Can transition to 2 different 3-color patterns
  - Can transition to 2 different 2-color patterns

- **From 2-color (ABA) to next row:**
  - Can transition to 2 different 3-color patterns
  - Can transition to 3 different 2-color patterns

### Recurrence Relations:
```
new_3_colors = 2 * count_3_colors + 2 * count_2_colors
new_2_colors = 2 * count_3_colors + 3 * count_2_colors
```

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | Single loop from 2 to n |
| **Space** | O(1) | Only storing two counters |

Where `n` is the number of rows in the grid.

---

## Key Takeaways

- State compression: Instead of tracking all possible patterns, group them by type
- Pattern analysis: Understanding the transition rules between row patterns
- Modular arithmetic: Handle large numbers with MOD operation
- This is a classic DP problem where recognizing the pattern structure simplifies the solution

---

## Files

- [solution.py](solution.py) - Python implementation

````
