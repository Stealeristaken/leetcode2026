# Day 008 - Max Dot Product of Two Subsequences

**Date:** January 8, 2026  
**LeetCode #:** 1458  
**Difficulty:** Hard  
**Link:** [Max Dot Product of Two Subsequences](https://leetcode.com/problems/max-dot-product-of-two-subsequences/)

---

## Problem Description

Given two arrays `nums1` and `nums2`, return the **maximum dot product** between **non-empty** subsequences of `nums1` and `nums2` with the same length.

A subsequence of an array is a new array formed by deleting some (can be none) elements without disturbing the relative positions of the remaining elements.

### Example 1:
```
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
```

### Example 2:
```
Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and [7] from nums2.
Their dot product is (3*7) = 21.
```

### Example 3:
```
Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and [1] from nums2.
Their dot product is -1.
```

---

## Solution Approach

### Method: 2D Dynamic Programming

Define `dp[i][j]` as the maximum dot product using elements from `nums1[0..i]` and `nums2[0..j]`.

### Transitions:

For each position `(i, j)`, we have choices:

1. **Take both elements:** `nums1[i] * nums2[j]` (start new subsequence or extend existing)
2. **Skip nums1[i]:** Use `dp[i-1][j]`
3. **Skip nums2[j]:** Use `dp[i][j-1]`

```
dp[i][j] = max(
    nums1[i] * nums2[j],                    // start fresh
    dp[i-1][j-1] + nums1[i] * nums2[j],     // extend previous
    dp[i-1][j],                              // skip nums1[i]
    dp[i][j-1]                               // skip nums2[j]
)
```

### Base Cases:
- `dp[0][0] = nums1[0] * nums2[0]`
- First row/column: max of current product or previous best

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(m × n) | Fill entire DP table |
| **Space** | O(m × n) | 2D DP array |

Where `m` and `n` are lengths of `nums1` and `nums2`.

---

## Key Takeaways

- Classic 2D DP pattern similar to LCS (Longest Common Subsequence)
- Key insight: at each step, decide to include current pair or skip
- Initialize with `-inf` to handle negative numbers correctly
- Must select at least one element from each array (non-empty subsequence)

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation
