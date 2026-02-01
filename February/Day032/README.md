# Day 032 - Divide an Array Into Subarrays With Minimum Cost I

**Date:** February 1, 2026  
**LeetCode #:** 3010  
**Difficulty:** Easy  
**Link:** [Divide an Array Into Subarrays With Minimum Cost I](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/)

---

## Problem Description

You are given an array of integers `nums` of length `n`.

The **cost** of an array is the value of its **first** element. For example, the cost of `[1,2,3]` is `1` while the cost of `[3,4,1]` is `3`.

You need to divide `nums` into **3 disjoint contiguous subarrays**.

Return the **minimum** possible sum of the cost of these subarrays.

### Example 1:
```
Input: nums = [1,2,3,12]
Output: 6
Explanation: The best way to form 3 subarrays is: [1], [2], [3,12]
Cost = 1 + 2 + 3 = 6
```

### Example 2:
```
Input: nums = [5,4,3]
Output: 12
Explanation: The best way to form 3 subarrays is: [5], [4], [3]
Cost = 5 + 4 + 3 = 12
```

### Example 3:
```
Input: nums = [10,3,1,1]
Output: 12
Explanation: The best way to form 3 subarrays is: [10,3], [1], [1]
Cost = 10 + 1 + 1 = 12
```

---

## Solution Approach

### Method: Find Two Smallest Elements

The key insight is that:
- The first subarray **must** start at index 0, so `nums[0]` is always included in the cost
- We need to find where to split to minimize the cost of the other two subarrays
- The cost of the 2nd and 3rd subarrays are their first elements
- Therefore, we need to find the **two smallest elements** from `nums[1:]`

### Algorithm:
1. Start with `nums[0]` as a fixed cost
2. Track the two smallest values (`x1` and `x2`) from index 1 onwards
3. Use `exchange` to efficiently update the two minimums in one pass
4. Return `nums[0] + x1 + x2`

### Time Complexity
- **O(n)** - Single pass through the array

### Space Complexity
- **O(1)** - Only using constant extra space

---

## Key Insights

1. **Fixed First Element:** The first subarray must start at index 0, so `nums[0]` is unavoidable
2. **Greedy Selection:** We greedily pick the two smallest elements as starting points for subarrays 2 and 3
3. **No Need for DP:** Since we only need 3 subarrays and the first element is fixed, a simple greedy approach works

