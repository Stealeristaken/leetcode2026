# Day 020 - Construct the Minimum Bitwise Array I

**Date:** January 20, 2026  
**LeetCode #:** 3314  
**Difficulty:** Easy  
**Link:** [Construct the Minimum Bitwise Array I](https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/)

---

## Problem Description

You are given an array `nums` consisting of `n` prime numbers.

You need to construct an array `ans` of length `n`, such that for each index `i`, the bitwise OR of `ans[i]` and `ans[i] + 1` equals `nums[i]`, i.e., `ans[i] OR (ans[i] + 1) == nums[i]`.

Return the array `ans`. If no valid `ans[i]` exists, set `ans[i] = -1`.

### Example 1:
```
Input: nums = [2,3,5,7]
Output: [-1,1,4,3]
Explanation:
- 2: No valid answer (2 is even)
- 3: 1 OR 2 = 3 ✓
- 5: 4 OR 5 = 5 ✓
- 7: 3 OR 4 = 7 ✓
```

### Example 2:
```
Input: nums = [11,13,31]
Output: [9,12,15]
```

---

## Solution Approach

### Method: Bit Manipulation

The key insight: `x OR (x+1)` always produces an odd number (the +1 sets the lowest bit). So even numbers in nums have no solution.

### Algorithm:

1. **If n is even:** Return -1 (no solution exists)

2. **If n is odd:**
   - Find the lowest 0 bit in `(n+1)` → this is where the "carry" stops
   - The answer is `n` with that bit cleared
   - Formula: `z = ((n+1) & ~n) >> 1`, then `ans = n & ~z`

### Why This Works:

For `x OR (x+1) = n`:
- `x+1` differs from `x` in a sequence of bits from the lowest 0 upward
- The OR combines these, filling in a consecutive sequence of 1s
- To reverse: find where that sequence ends and clear one bit

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | Single pass through array |
| **Space** | O(n) | Output array |

Where `n` is the length of the input array.

---

## Key Takeaways

- `x OR (x+1)` always has the lowest bit set (odd result)
- Bit manipulation to find lowest 0: `(n+1) & ~n`
- Understanding binary addition carry propagation
- Even inputs are impossible cases

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation
