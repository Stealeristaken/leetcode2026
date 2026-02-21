# Day 052 - Prime Number of Set Bits in Binary Representation

**Date:** February 21, 2026  
**LeetCode #:** 762  
**Difficulty:** Easy  
**Link:** [Prime Number of Set Bits in Binary Representation](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/)

---

## Problem Description

Given two integers `left` and `right`, return the count of numbers in the inclusive range `[left, right]` having a **prime number of set bits** in their binary representation.

Recall that the number of set bits an integer has is the number of `1`s present when written in binary.

### Example 1:
```
Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110  (2 set bits, 2 is prime)
7  -> 111  (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
```

### Example 2:
```
Input: left = 10, right = 15
Output: 5
```

---

## Solution Approach

Precompute non-prime numbers via a sieve up to 32 (max possible set bits for numbers ≤ 10^6). For each number in the range, count its set bits and check if that count is prime.

---

## Code

See `solution.py` for the implementation.
