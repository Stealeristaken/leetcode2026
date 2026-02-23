# Day 054 - Check If a String Contains All Binary Codes of Size K

**Date:** February 23, 2026  
**LeetCode #:** 1461  
**Difficulty:** Medium  
**Link:** [Check If a String Contains All Binary Codes of Size K](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)

---

## Problem Description

Given a binary string `s` and an integer `k`, return `true` if every binary code of length `k` is a substring of `s`. Otherwise, return `false`.

### Example 1:
```
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10", "11".
They can be found as substrings at indices 0, 1, 3, 2 respectively.
```

### Example 2:
```
Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", both present.
```

### Example 3:
```
Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is not a substring of s.
```

---

## Solution Approach

Use a sliding window of size `k` to extract all substrings. Track visited codes with a bitset for O(1) lookup. Early exit if the string is too short to contain all `2^k` codes.

---

## Code

See `solution.cpp` for the implementation.
