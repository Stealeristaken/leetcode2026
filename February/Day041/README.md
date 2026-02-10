# Day 041 - Longest Balanced Subarray

**Date:** February 10, 2026  
**LeetCode #:** 3522  
**Difficulty:** Medium  
**Link:** [Longest Balanced Subarray](https://leetcode.com/problems/longest-balanced-subarray/)

---

## Problem Description

Given an integer array `nums`, find the length of the longest subarray that contains the same number of **unique even** numbers and **unique odd** numbers.

### Example 1:
```
Input: nums = [1,2,3,4,5,6]
Output: 6
Explanation: The entire array has 3 unique even numbers (2, 4, 6) and 3 unique odd numbers (1, 3, 5).
```

### Example 2:
```
Input: nums = [1,2,1,2]
Output: 4
Explanation: The array has 1 unique even (2) and 1 unique odd (1), making it balanced.
```

---

## Solution Approach

### Method: Sliding Window with Uniqueness Tracking

The algorithm uses a two-pointer approach to check all subarrays:

1. **Outer Loop:** Iterate through each starting position `i`
   
2. **Inner Loop:** Extend the subarray from `i` to `j`
   - Use a `seen` array to track which elements have been counted for the current starting position
   - Mark elements with `i + 1` to distinguish between different starting positions
   
3. **Count Unique Elements:** For each element:
   - If not seen in current subarray, increment either even count `A[0]` or odd count `A[1]`
   - Check parity using `val & 1`

4. **Check Balance:** When unique evens equals unique odds, update the result

### Time Complexity
- **O(n²)** - Two nested loops iterating through all subarrays

### Space Complexity
- **O(max(nums))** - Seen array to track unique elements
