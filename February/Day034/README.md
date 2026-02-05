# Day 034 - Check if Array is Trionic

**Date:** February 3, 2026  
**LeetCode #:** 3534  
**Difficulty:** Medium  
**Link:** [Check if Array is Trionic](https://leetcode.com/problems/check-if-array-is-sorted/)

---

## Problem Description

An array is called **trionic** if it can be split into three non-empty contiguous parts such that:
1. The first part is **strictly increasing**
2. The second part is **strictly decreasing**  
3. The third part is **strictly increasing**

Given an array `nums`, return `true` if the array is trionic, otherwise return `false`.

### Example 1:
```
Input: nums = [1,2,3,2,1,2,3]
Output: true
Explanation: Split at indices p=2, q=4: [1,2,3], [2,1], [2,3]
- [1,2,3] is strictly increasing
- [3,2,1] is strictly decreasing  
- [1,2,3] is strictly increasing
```

### Example 2:
```
Input: nums = [1,2,3,4,5]
Output: false
Explanation: Cannot find a valid split into increasing-decreasing-increasing pattern.
```

---

## Solution Approach

### Method: Brute Force Enumeration

The algorithm tries all possible split points `p` and `q`:

1. **Enumerate Split Points:** Try all pairs `(p, q)` where `1 ≤ p < q < n-1`
2. **Validate Each Segment:**
   - Check if `nums[0..p]` is strictly increasing
   - Check if `nums[p..q]` is strictly decreasing
   - Check if `nums[q..n-1]` is strictly increasing
3. **Return True** if any valid split is found

### Helper Functions:
- `isIncreasing(l, r)`: Returns true if subarray from index `l` to `r` is strictly increasing
- `isDecreasing(l, r)`: Returns true if subarray from index `l` to `r` is strictly decreasing

### Time Complexity
- **O(n³)** - O(n²) split point pairs × O(n) validation per split

### Space Complexity
- **O(1)** - Only using constant extra space

---

## Key Insights

1. **Three Segments:** The array must have at least 4 elements to have three non-empty parts
2. **Strict Inequalities:** Both increasing and decreasing must be strict (no equal consecutive elements)
3. **Brute Force Works:** For small inputs, checking all split points is straightforward and correct

