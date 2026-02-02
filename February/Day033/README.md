# Day 033 - Divide an Array Into Subarrays With Minimum Cost II

**Date:** February 2, 2026  
**LeetCode #:** 3013  
**Difficulty:** Hard  
**Link:** [Divide an Array Into Subarrays With Minimum Cost II](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/)

---

## Problem Description

You are given a **0-indexed** array of integers `nums` of length `n`, and two **positive** integers `k` and `dist`.

The **cost** of an array is the value of its **first** element. For example, the cost of `[1,2,3]` is `1` while the cost of `[3,4,1]` is `3`.

You need to divide `nums` into `k` **disjoint contiguous subarrays**, such that the difference between the starting index of the **second** subarray and the starting index of the **k-th** subarray is **less than or equal to** `dist`.

Return the **minimum** possible sum of the cost of these subarrays.

### Example 1:
```
Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
Output: 5
Explanation: The best way to divide nums into 3 subarrays is: [1,3], [2,6,4], [2].
Cost = 1 + 2 + 2 = 5
```

### Example 2:
```
Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
Output: 15
Explanation: The best way to divide nums into 4 subarrays is: [10], [1], [2], [2,2,1].
Cost = 10 + 1 + 2 + 2 = 15
```

---

## Solution Approach

### Method: Sliding Window with SortedList

The key insight is that:
- `nums[0]` is always part of the cost (first subarray must start at index 0)
- We need to select `k-1` more starting points within a window of size `dist`
- Use a **sliding window** to track valid candidates and maintain the `k-1` smallest elements

### Algorithm:
1. Remove `nums[0]` and add it to the base cost
2. Use a `SortedList` to maintain elements in the current window of size `dist`
3. Track the sum of the `k-2` smallest elements (since we need `k-1` more starting points after the first)
4. Slide the window: add new element, update cost, track minimum, remove old element
5. Use the property that `SortedList[k]` gives quick access to the k-th smallest element

### Time Complexity
- **O(n log n)** - Each insertion/removal in SortedList is O(log n)

### Space Complexity
- **O(dist)** - The SortedList stores at most `dist` elements

---

## Key Insights

1. **Sliding Window Constraint:** The `dist` constraint limits where subarray starting points can be placed
2. **Sorted Container:** Using `SortedList` allows O(log n) insertions/deletions while maintaining sorted order
3. **Incremental Cost Update:** Instead of recalculating the sum of k smallest each time, we incrementally update using the k-th element as a threshold

