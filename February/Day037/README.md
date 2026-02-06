# Day 037 - Minimum Removal to Make Array Values Within K Ratio

**Date:** February 6, 2026  
**LeetCode #:** 3380  
**Difficulty:** Medium  
**Link:** [Minimum Removal to Make Array Values Within K Ratio](https://leetcode.com/problems/minimum-removal-to-make-array-values-within-k-ratio/)

---

## Problem Description

Given an integer array `nums` and an integer `k`, return the **minimum number of elements** you need to remove from the array such that for any two remaining elements `nums[i]` and `nums[j]`, the condition `nums[j] <= nums[i] * k` is satisfied.

In other words, after removal, the ratio between the maximum and minimum element should be at most `k`.

### Example 1:
```
Input: nums = [1,2,3,10], k = 2
Output: 1
Explanation: Remove 10. The remaining array [1,2,3] satisfies 3 <= 1*2? No.
Actually remove 1: [2,3,10] -> 10 <= 2*2? No. Remove [1,10]: [2,3] -> 3 <= 2*2 = 4 ✓
```

### Example 2:
```
Input: nums = [1,1,1,1], k = 1
Output: 0
Explanation: All elements are equal, so max/min ratio is 1 which satisfies k=1.
```

### Constraints:
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^9`

---

## Solution Approach

### Method: Sorting + Sliding Window

The key insight is that after sorting, we need to find the **longest subarray** where `max <= min * k`.

### Algorithm:
1. **Sort the array** - This ensures elements are in order, so we only need to check `nums[j] <= nums[i] * k` for the window endpoints
2. **Sliding window** - Use two pointers to find the maximum window where all elements satisfy the ratio constraint
3. **Calculate removals** - Answer is `n - maxWindowSize`

### Complexity:
- **Time:** O(n log n) - dominated by sorting
- **Space:** O(1) - only using pointers

---

## Code

### Python

```python
class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums) 

        i = 0 
        maxi = 1 

        for j in range(n):
            while nums[j] > nums[i] * k: 
                i += 1 
            maxi = max(maxi, j - i + 1)

        return n - maxi
```
