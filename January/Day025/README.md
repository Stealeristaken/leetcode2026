# Day 025 - Minimum Difference Between Highest and Lowest of K Scores

**Date:** January 25, 2026  
**LeetCode #:** 1984  
**Difficulty:** Easy  
**Link:** [Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/)

---

## Problem Description

You are given a **0-indexed** integer array `nums`, where `nums[i]` represents the score of the `i`th student. You are also given an integer `k`.

Pick the scores of any `k` students from the array so that the **difference** between the **highest** and the **lowest** of the `k` scores is **minimized**.

Return the **minimum** possible difference.

### Example 1:
```
Input: nums = [90], k = 1
Output: 0
Explanation: There is one way to pick score(s) of one student:
- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
```

### Example 2:
```
Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: Pick scores of any 2 students from [9,4,1,7].
- [9,4]: difference = 9 - 4 = 5
- [9,1]: difference = 9 - 1 = 8
- [9,7]: difference = 9 - 7 = 2
- [4,1]: difference = 4 - 1 = 3
- [4,7]: difference = 7 - 4 = 3
- [1,7]: difference = 7 - 1 = 6
Minimum difference is 2.
```

---

## Solution Approach

### Method: Sorting + Sliding Window

Sort the array and use a fixed-size sliding window to find the minimum range containing `k` elements.

### Key Insight:

After sorting, the `k` students with the minimum score difference must be **consecutive** in the sorted array. This is because any gap would only increase the difference.

### Algorithm:

1. **Handle edge case:** If `k == 1`, return 0 (single element has no difference)

2. **Sort the array:** Arrange scores in ascending order

3. **Sliding window of size k:**
   - For each window starting at index `i`
   - The difference is `nums[i + k - 1] - nums[i]` (max - min in window)
   - Track the minimum difference across all windows

4. **Return** the minimum difference found

### Why Consecutive Elements:

In a sorted array `[1, 4, 7, 9]` with `k=2`:
- Consecutive pairs: (1,4)=3, (4,7)=3, (7,9)=2
- Non-consecutive would always be larger: (1,7)=6, (4,9)=5, (1,9)=8

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n log n) | Sorting dominates; sliding window is O(n) |
| **Space** | O(1) | Only constant extra space (excluding sort's internal space) |

Where `n` is the length of the input array.

---

## Key Takeaways

- Sorting transforms "find k elements with minimum range" into "find k consecutive elements"
- Fixed-size sliding window on sorted data is a common pattern
- In sorted arrays, consecutive elements always have the smallest range

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
