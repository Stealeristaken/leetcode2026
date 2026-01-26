# Day 016 - Maximum Square Area by Removing Fences From a Field

**Date:** January 16, 2026  
**LeetCode #:** 2975  
**Difficulty:** Medium  
**Link:** [Maximum Square Area by Removing Fences From a Field](https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/)

---

## Problem Description

There is a large `(m - 1) x (n - 1)` rectangular field with corners at `(1, 1)` and `(m, n)` containing some horizontal and vertical fences given in arrays `hFences` and `vFences`.

Return the **maximum area** of a square field that can be formed by removing some fences (possibly none). Since the answer may be large, return it modulo `10^9 + 7`. If it is impossible to form a square field, return `-1`.

### Example 1:
```
Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 
creates a 2×2 square.
```

### Example 2:
```
Input: m = 6, n = 7, hFences = [2], vFences = [4]
Output: -1
Explanation: No square can be formed.
```

---

## Solution Approach

### Method: Gap Enumeration with Hash Set

Find all possible gap sizes in both dimensions and check for common values.

### Algorithm:

1. **Add boundaries** (1 and m/n) to fence arrays
2. **Sort** both arrays
3. **Calculate all possible gaps:**
   - For horizontal: enumerate all pairs (i, j) and calculate sum of consecutive gaps
   - Store all possible horizontal gap sizes in a hash set
4. **Check vertical gaps:**
   - For each possible vertical gap size, check if it exists in horizontal set
   - Track maximum matching gap
5. **Return** maxGap² mod (10⁹ + 7), or -1 if no match

### Why Enumerate All Gaps?

Removing consecutive fences creates gaps that can be summed. We need to find a gap size achievable in both dimensions.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(h² + v²) | Enumerate all gap combinations |
| **Space** | O(h²) | Hash set for horizontal gaps |

Where `h` and `v` are lengths of hFences and vFences.

---

## Key Takeaways

- Similar to Day015 but allows non-consecutive fence removal
- Hash set efficiently checks for common gap sizes
- Add boundary fences to handle edge cases
- Modulo only at the end (after finding max)

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
