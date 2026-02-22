# Day 053 - Binary Gap

**Date:** February 22, 2026  
**LeetCode #:** 868  
**Difficulty:** Easy  
**Link:** [Binary Gap](https://leetcode.com/problems/binary-gap/)

---

## Problem Description

Given a positive integer `n`, find and return the **longest distance** between any two adjacent `1`s in the binary representation of `n`. If there are no two adjacent `1`s, return `0`.

Two `1`s are adjacent if there are only `0`s separating them (possibly no `0`s).

The **distance** between two `1`s is the absolute difference of their bit positions. The bit position of the rightmost bit is `0`, and increases by `1` for each bit moving to the left.

### Example 1:
```
Input: n = 22
Output: 2
Explanation: 22 in binary is "10110". The adjacent 1s are at positions 1, 2, and 4.
The longest distance between any two adjacent 1s is 4 - 2 = 2.
```

### Example 2:
```
Input: n = 8
Output: 0
Explanation: 8 in binary is "1000". There are not any adjacent 1s, so return 0.
```

---

## Solution Approach

Iterate through the bits of `n` from right to left. Track the distance from the last seen `1` bit and update the max distance whenever another `1` is encountered.

---

## Code

See `solution.py` for the implementation.
