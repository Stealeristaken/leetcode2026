# Day 036 - Transformed Array

**Date:** February 5, 2026  
**LeetCode #:** 3379  
**Difficulty:** Easy  
**Link:** [Transformed Array](https://leetcode.com/problems/transformed-array/)

---

## Problem Description

You are given an integer array `nums` that represents a circular array. Your task is to create a new array `result` of the same size, following these rules:

For each index `i` (where `0 <= i < nums.length`), perform the following independent actions:
- If `nums[i] > 0`: Start at index `i` and move `nums[i]` steps to the **right** in the circular array. Set `result[i]` to the value of the index where you land.
- If `nums[i] < 0`: Start at index `i` and move `abs(nums[i])` steps to the **left** in the circular array. Set `result[i]` to the value of the index where you land.
- If `nums[i] == 0`: Set `result[i]` to `nums[i]`.

Return the new array `result`.

**Note:** Since `nums` is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.

### Example 1:
```
Input: nums = [3,-2,1,1]
Output: [1,1,1,3]
Explanation:
- nums[0] = 3: Move 3 steps right → land at nums[3] = 1
- nums[1] = -2: Move 2 steps left → land at nums[3] = 1
- nums[2] = 1: Move 1 step right → land at nums[3] = 1
- nums[3] = 1: Move 1 step right → land at nums[0] = 3
```

### Example 2:
```
Input: nums = [-1,4,-1]
Output: [-1,-1,4]
Explanation:
- nums[0] = -1: Move 1 step left → land at nums[2] = -1
- nums[1] = 4: Move 4 steps right → land at nums[2] = -1
- nums[2] = -1: Move 1 step left → land at nums[1] = 4
```

### Constraints:
- `1 <= nums.length <= 100`
- `-100 <= nums[i] <= 100`

---

## Solution Approach

### Method: Direct Simulation with Modular Arithmetic

The key insight is that Python's modulo operator handles negative numbers correctly for circular indexing.

### Algorithm:
1. For each index `i`, calculate the target index: `(i + nums[i]) % n`
2. Set `result[i]` to `nums[target_index]`
3. Python's `%` naturally handles both positive and negative offsets

### Complexity:
- **Time:** O(n) - single pass through the array
- **Space:** O(n) - for the result array

---

## Code

### Python

```python
from typing import List

class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        
        for i in range(n):
            target_index = (i + nums[i]) % n
            result[i] = nums[target_index]
            
        return result
```
