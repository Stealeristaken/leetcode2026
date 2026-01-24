# Day 024 - Minimize Maximum Pair Sum in Array

**Date:** January 24, 2026  
**LeetCode #:** 1877  
**Difficulty:** Medium  
**Link:** [Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/)

---

## Problem Description

The **pair sum** of a pair `(a,b)` is equal to `a + b`. The **maximum pair sum** is the largest **pair sum** in a list of pairs.

Given an array `nums` of **even** length `n`, pair up the elements of `nums` into `n / 2` pairs such that:

- Each element of `nums` is in **exactly one** pair, and
- The **maximum pair sum** is **minimized**.

Return the minimized maximum pair sum after optimally pairing up the elements.

### Example 1:
```
Input: nums = [3,5,2,3]
Output: 7
Explanation: The elements can be paired up into pairs (3,3) and (5,2).
The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
```

### Example 2:
```
Input: nums = [3,5,4,2,4,6]
Output: 8
Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
```

---

## Solution Approach

### Method: Counting Sort + Two Pointers

Use counting sort (frequency array) for O(n) sorting, then greedily pair smallest with largest.

### Key Insight:

To minimize the maximum pair sum, pair the **smallest** element with the **largest**, the second smallest with the second largest, and so on. This balances the sums across all pairs.

### Algorithm:

1. **Build frequency array:**
   - Track min and max values while building
   - Count occurrences of each number

2. **Two-pointer pairing:**
   - Left pointer starts at minimum value
   - Right pointer starts at maximum value
   - Skip values with zero frequency
   - Pair elements from both ends, track maximum sum
   - Decrement frequencies after pairing

3. **Return** the maximum sum encountered

### Why This Works:

- Pairing extremes together "balances" the sums
- If we paired two large numbers, their sum would be huge
- Counting sort avoids O(n log n) comparison-based sorting

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n + k) | Build frequency array O(n), two-pointer traversal O(k) where k = max - min |
| **Space** | O(k) | Frequency array of size 100001 (constraint: 1 ≤ nums[i] ≤ 10^5) |

Where `n` is the length of the input array.

---

## Key Takeaways

- Counting sort is O(n) when range is known and bounded
- Two-pointer technique on sorted data for optimal pairing
- Greedy pairing of extremes minimizes maximum pair sum
- Frequency array enables efficient "virtual sorting" without actual sorting

---

## Files

- [solution.py](solution.py) - Python implementation
