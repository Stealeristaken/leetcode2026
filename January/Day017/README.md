# Day 017 - Find the Largest Area of Square Inside Two Rectangles

**Date:** January 17, 2026  
**LeetCode #:** 3047  
**Difficulty:** Medium  
**Link:** [Find the Largest Area of Square Inside Two Rectangles](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/)

---

## Problem Description

You are given two 2D integer arrays `bottomLeft` and `topRight` representing the coordinates of `n` rectangles.

Find the **largest square** that can fit inside the intersection of any two rectangles. Return the area of such square, or `0` if no such square exists.

### Example 1:
```
Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
Output: 1
Explanation: A 1×1 square fits in the intersection of rectangles 0 and 1.
```

### Example 2:
```
Input: bottomLeft = [[1,1],[1,3],[1,5]], topRight = [[5,5],[5,7],[5,9]]
Output: 4
Explanation: A 2×2 square fits in the intersection.
```

---

## Solution Approach

### Method: Brute Force Pairwise Intersection

Check all pairs of rectangles and find the largest square that fits in their intersection.

### Algorithm:

1. **For each pair of rectangles (i, j):**
   - Calculate intersection rectangle:
     - `left = max(x1_i, x1_j)`
     - `right = min(x2_i, x2_j)`
     - `bottom = max(y1_i, y1_j)`
     - `top = min(y2_i, y2_j)`
   - `width = right - left`
   - `height = top - bottom`

2. **Square side = min(width, height)**
   - If positive, intersection exists

3. **Track maximum** square side across all pairs

4. **Return** maxSide²

### Intersection Check:

If `width > 0` and `height > 0`, rectangles intersect.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n²) | Check all pairs of rectangles |
| **Space** | O(1) | Only constant extra variables |

Where `n` is the number of rectangles.

---

## Key Takeaways

- Rectangle intersection: max of mins, min of maxs
- Square constraint: take minimum of width and height
- Brute force is acceptable for small n
- Clean coordinate geometry problem

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
