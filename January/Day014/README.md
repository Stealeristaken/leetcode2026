# Day 014 - Separate Squares II

**Date:** January 14, 2026  
**LeetCode #:** 3454  
**Difficulty:** Hard  
**Link:** [Separate Squares II](https://leetcode.com/problems/separate-squares-ii/)

---

## Problem Description

You are given a 2D integer array `squares` where `squares[i] = [xi, yi, li]` represents the coordinates of the bottom-left point and the side length of the i-th square.

Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

**Note:** Squares may overlap, and overlapping areas should only be counted once.

Answers within `10^-5` of the actual answer will be accepted.

### Example 1:
```
Input: squares = [[0,0,1],[2,2,1]]
Output: 1.0
```

### Example 2:
```
Input: squares = [[0,0,2],[1,1,1]]
Output: 1.0
```

---

## Solution Approach

### Method: Sweep Line + Segment Tree with Coordinate Compression

Unlike Separate Squares I, overlapping areas must be counted only once. This requires a more sophisticated approach.

### Algorithm:

1. **Coordinate Compression (X-axis):**
   - Collect all unique x-coordinates from square edges
   - Map them to indices for the segment tree

2. **Create Sweep Line Events:**
   - For each square: bottom edge (enter, +1) and top edge (leave, -1)
   - Sort events by y-coordinate

3. **Segment Tree for Active Width:**
   - `count[node]`: how many squares fully cover this interval
   - `length[node]`: actual length covered (handles overlaps!)
   - When count > 0: entire interval is covered
   - When count = 0: sum children's lengths

4. **Sweep from Bottom to Top:**
   - For each y-strip: area = active_width × height
   - Track cumulative area and strip info

5. **Binary Search for Split Point:**
   - Find the strip where cumulative area crosses half
   - Use linear interpolation for exact y-coordinate

### Why Segment Tree?

The segment tree efficiently computes the **union length** of active intervals, correctly handling overlapping squares.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n log n) | Sorting events + segment tree operations |
| **Space** | O(n) | Segment tree and events storage |

Where `n` is the number of squares.

---

## Key Takeaways

- Sweep line algorithm for 2D area problems
- Segment tree for efficient union of intervals
- Coordinate compression reduces problem size
- Count-based lazy propagation handles overlaps correctly
- Classic computational geometry technique

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation
