# Day 022 - Minimum Pair Removal to Sort Array I

**Date:** January 22, 2026  
**LeetCode #:** 3507  
**Difficulty:** Easy  
**Link:** [Minimum Pair Removal to Sort Array I](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/)

---

## Problem Description

Given an array `nums`, you can perform the following operation any number of times:

- Select the **adjacent pair** with the **minimum sum** and replace them with their sum.

Return the **minimum number of operations** needed to make the array **non-decreasing**.

### Example 1:
```
Input: nums = [5,2,3,1]
Output: 2
Explanation:
- Merge pair (3,1) with sum 4 → [5,2,4]
- Merge pair (2,4) with sum 6 → [5,6]
Array is now non-decreasing.
```

### Example 2:
```
Input: nums = [1,2,2]
Output: 0
Explanation: Array is already non-decreasing.
```

---

## Solution Approach

### Method: Greedy Simulation

Repeatedly find and merge the minimum sum adjacent pair until array is sorted.

### Algorithm:

1. **While array is not sorted:**
   - Find the adjacent pair with minimum sum
   - Merge them (replace with their sum, remove one element)
   - Increment operation counter

2. **Helper functions:**
   - `minPair(v)`: Find index of minimum sum adjacent pair
   - `mergePair(v, pos)`: Merge elements at pos and pos+1

### Why Greedy Works:

Merging the smallest sum pair minimizes the "disruption" to the array's order. Smaller merged values are easier to sort later.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n² × n log n) | At most n merges, each with O(n) scan + O(n log n) sort check |
| **Space** | O(n) | For sorted comparison |

Where `n` is the length of the input array.

---

## Key Takeaways

- Greedy approach: always merge minimum sum pair
- Check sorted condition after each operation
- Simple simulation works for small inputs
- Part II likely requires optimization (heap/sorted container)

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation
