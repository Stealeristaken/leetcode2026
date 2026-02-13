# Day 042 - Longest Balanced Subarray II

**Date:** February 11, 2026  
**LeetCode #:** 3523  
**Difficulty:** Hard  
**Link:** [Longest Balanced Subarray II](https://leetcode.com/problems/longest-balanced-subarray-ii/)

---

## Problem Description

Given an integer array `nums`, find the length of the longest subarray that contains the same number of **unique even** numbers and **unique odd** numbers.

This is the optimized version requiring better time complexity than O(n²).

### Example 1:
```
Input: nums = [1,2,3,4,5,6]
Output: 6
Explanation: The entire array has 3 unique even numbers (2, 4, 6) and 3 unique odd numbers (1, 3, 5).
```

---

## Solution Approach

### Method: Segment Tree with Lazy Propagation

The algorithm uses a segment tree to efficiently track balance states:

1. **Segment Tree Structure:**
   - `mn[]` - Stores minimum values in segments
   - `mx[]` - Stores maximum values in segments
   - `lazy[]` - Lazy propagation tags for range updates

2. **Key Operations:**
   - `push()` - Propagates lazy values to children
   - `update()` - Range update with lazy propagation
   - `findFirst()` - Find first position where balance equals zero

3. **Main Algorithm:**
   - Track last position of each element
   - Use segment tree to maintain balance differences
   - Find longest balanced subarray using segment queries

### Time Complexity
- **O(n log n)** - Each element triggers O(log n) segment tree operations

### Space Complexity
- **O(n)** - Segment tree arrays
