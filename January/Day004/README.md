````markdown
# Day 004 - Four Divisors

**Date:** January 4, 2026  
**LeetCode #:** 1390  
**Difficulty:** Medium  
**Link:** [Four Divisors](https://leetcode.com/problems/four-divisors/)

---

## Problem Description

Given an integer array `nums`, return the sum of divisors of the integers in that array that have **exactly four divisors**. If there is no such integer in the array, return `0`.

### Example 1:
```
Input: nums = [21,4,7]
Output: 32
Explanation:
- 21 has 4 divisors: 1, 3, 7, 21 → sum = 32
- 4 has 3 divisors: 1, 2, 4 → not counted
- 7 has 2 divisors: 1, 7 → not counted
Answer: 32
```

### Example 2:
```
Input: nums = [21,21]
Output: 64
Explanation: Each 21 contributes 32 to the sum.
```

### Example 3:
```
Input: nums = [1,2,3,4,5]
Output: 0
Explanation: No number has exactly 4 divisors.
```

---

## Solution Approach

### Method: Square Root Optimization

For each number, we find all divisors efficiently by only iterating up to √n:

1. **Iterate from 1 to √num:** For each divisor `i` found:
   - If `i * i == num`: It's a perfect square, count only once
   - Otherwise: Both `i` and `num/i` are divisors, count both

2. **Early termination:** If divisor count exceeds 4, skip to next number

3. **Collect result:** If exactly 4 divisors found, add their sum to total

### Why Square Root?
Every divisor `d` of `n` has a complementary divisor `n/d`. By checking up to √n, we find both divisors in each pair, cutting the search space significantly.

### Numbers with Exactly 4 Divisors:
- **p³** (cube of prime): divisors are 1, p, p², p³
- **p × q** (product of two distinct primes): divisors are 1, p, q, pq

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n × √m) | For each of n numbers, check up to √m divisors |
| **Space** | O(1) | Only using constant extra space |

Where `n` is the length of the array and `m` is the maximum value in the array.

---

## Key Takeaways

- Square root optimization is essential for divisor problems
- Early termination improves average case performance
- Perfect squares need special handling (divisor counted once, not twice)
- Understanding number theory helps: numbers with 4 divisors are either p³ or p×q

---

## Files

- [solution.py](solution.py) - Python implementation

````
