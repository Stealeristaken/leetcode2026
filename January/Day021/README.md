# Day 021 - Construct the Minimum Bitwise Array II

**Date:** January 21, 2026  
**LeetCode #:** 3315  
**Difficulty:** Medium  
**Link:** [Construct the Minimum Bitwise Array II](https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/)

---

## Problem Description

You are given an array `nums` consisting of `n` prime numbers.

You need to construct an array `ans` of length `n`, such that for each index `i`, the bitwise OR of `ans[i]` and `ans[i] + 1` equals `nums[i]`, i.e., `ans[i] OR (ans[i] + 1) == nums[i]`.

Return the array `ans`. If no valid `ans[i]` exists, set `ans[i] = -1`.

### Example 1:
```
Input: nums = [2,3,5,7]
Output: [-1,1,4,3]
```

### Example 2:
```
Input: nums = [11,13,31]
Output: [9,12,15]
```

---

## Solution Approach

### Method: Optimized Bit Manipulation

This is the same problem as Day020 but with larger constraints, requiring a more efficient formula.

### Algorithm:

1. **Special case:** If `n == 2`, return -1 (only even prime, no solution)

2. **For all other primes (odd numbers):**
   - Find the lowest set bit position in `(n+1)` that was 0 in `n`
   - Use formula: `ans = n - ((n+1) & (-n-1)) / 2`

### Formula Breakdown:

- `(n+1) & (-n-1)`: Isolates the lowest bit that "carried" when adding 1
- Dividing by 2: Shifts right by 1
- Subtracting from n: Clears the appropriate bit

### Why n == 2 is Special:

2 in binary is `10`. For `x OR (x+1) = 2`:
- Need result with bit pattern `10`
- But `x OR (x+1)` always sets the lowest bit → impossible

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | Single pass, O(1) per element |
| **Space** | O(n) | Output array |

Where `n` is the length of the input array.

---

## Key Takeaways

- Same logic as Part I but with optimized bit formula
- `-n-1` equals `~n` (two's complement trick)
- `(n+1) & (-n-1)` finds the rightmost bit flipped by +1
- Understanding binary arithmetic is key for bit manipulation

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation
