# Day 026 - Minimum Absolute Difference

**Date:** January 26, 2026  
**LeetCode #:** 1200  
**Difficulty:** Easy  
**Link:** [Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)

---

## Problem Description

Given an array of **distinct** integers `arr`, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order (with respect to pairs), each pair `[a, b]` follows:

- `a, b` are from `arr`
- `a < b`
- `b - a` equals the minimum absolute difference of any two elements in `arr`

### Example 1:
```
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
```

### Example 2:
```
Input: arr = [1,3,6,10,15]
Output: [[1,3]]
```

### Example 3:
```
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
```

---

## Solution Approach

### Method: Sorting + Single Pass

Sort the array and find all adjacent pairs with the minimum difference in one pass.

### Key Insight:

In a sorted array, the minimum absolute difference can **only** occur between **adjacent elements**. Non-adjacent elements will always have a larger or equal difference.

### Algorithm:

1. **Sort the array** in ascending order

2. **Single pass through adjacent pairs:**
   - Calculate difference between consecutive elements
   - If smaller than current minimum: clear result, update minimum, add pair
   - If equal to current minimum: add pair to result

3. **Return** the list of pairs (already in ascending order due to sorting)

### Why Adjacent Only:

For sorted array `[a, b, c]` where `a < b < c`:
- `c - a = (c - b) + (b - a)` which is always ≥ `min(c-b, b-a)`
- So minimum difference must be between adjacent elements

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n log n) | Sorting dominates; single pass is O(n) |
| **Space** | O(1) | Only output space (excluding sort's internal space) |

Where `n` is the length of the input array.

---

## Key Takeaways

- Sorting reduces "find minimum difference pairs" to checking only adjacent elements
- Single-pass tracking of minimum with result clearing avoids two-pass solution
- In sorted distinct arrays, minimum difference is always between neighbors

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
