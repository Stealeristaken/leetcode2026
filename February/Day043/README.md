# Day 043 - Longest Balanced Substring

**Date:** February 12, 2026  
**LeetCode #:** 3524  
**Difficulty:** Medium  
**Link:** [Longest Balanced Substring](https://leetcode.com/problems/longest-balanced-substring/)

---

## Problem Description

Given a string `s` consisting of lowercase letters, find the length of the longest **balanced** substring. A substring is balanced if every distinct character appears the same number of times.

### Example 1:
```
Input: s = "aabbcc"
Output: 6
Explanation: All characters 'a', 'b', 'c' appear exactly 2 times.
```

### Example 2:
```
Input: s = "abab"
Output: 4
Explanation: Characters 'a' and 'b' each appear 2 times.
```

---

## Solution Approach

### Method: Brute Force with Frequency Tracking

The algorithm checks all substrings using two nested loops:

1. **Outer Loop:** Iterate through each starting position `i`

2. **Inner Loop:** Extend substring from `i` to `j`
   - Maintain frequency map for each character
   - Track `maxFreq` (maximum frequency of any character)
   - Track `distincts` (number of distinct characters)

3. **Balance Check:** A substring is balanced when:
   - Length equals `distincts * maxFreq`
   - This means all distinct characters appear exactly `maxFreq` times

### Time Complexity
- **O(n²)** - Two nested loops, O(1) balance check

### Space Complexity
- **O(26)** = **O(1)** - Fixed-size frequency array for lowercase letters
