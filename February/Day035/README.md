# Day 035 - Maximum Sum Trionic Subarray

**Date:** February 4, 2026  
**LeetCode #:** 3535  
**Difficulty:** Hard  
**Link:** [Maximum Sum Trionic Subarray](https://leetcode.com/problems/maximum-sum-trionic-subarray/)

---

## Problem Description

A subarray is called **trionic** if it consists of three contiguous parts such that:
1. The first part is **strictly increasing**
2. The second part is **strictly decreasing**
3. The third part is **strictly increasing**

Given an array `nums`, return the **maximum sum** of any trionic subarray. If no trionic subarray exists, return the minimum possible value.

### Example 1:
```
Input: nums = [1,2,3,2,1,2,3]
Output: 14
Explanation: The entire array [1,2,3,2,1,2,3] is trionic with sum = 1+2+3+2+1+2+3 = 14
```

### Example 2:
```
Input: nums = [1,2,3,4,5]
Output: -inf
Explanation: No trionic subarray exists since we need increasing-decreasing-increasing pattern.
```

---

## Solution Approach

### Method: Dynamic Programming with State Tracking

The algorithm uses DP to track three states as we iterate through the array:

1. **State `a`:** Maximum sum ending at current position in the first increasing segment
2. **State `b`:** Maximum sum ending at current position in the decreasing segment
3. **State `c`:** Maximum sum ending at current position in the third increasing segment

### Transitions:
- **If `curr > prev` (increasing):** 
  - Update state `a`: Extend or start the first increasing segment
  - Update state `c`: Transition from decreasing to third increasing segment
- **If `curr < prev` (decreasing):**
  - Update state `b`: Transition from first increasing to decreasing segment

### Complexity:
- **Time:** O(n) - single pass through the array
- **Space:** O(1) - only tracking constant number of states

---

## Code

### C++

```cpp
class Solution {
public:
    long long maxSumTrionic(const vector<int>& nums) {
        const long long INF = -1e17;
        long long result = INF, a = INF, b = INF, c = INF;
        long long prev = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            long long curr = nums[i];
            auto na = INF, nb = INF, nc = INF;
            if (curr > prev) { // increasing, update first and third state
                na = max(a, prev) + curr;
                nc = max(b, c) + curr;
            } else if (curr < prev) { // decreasing, update second state
                nb = max(a, b) + curr;
            }
            a = na, b = nb, c = nc;
            result = max(result, c);
            prev = curr;
        }
        return result;
    }
};
```
