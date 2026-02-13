# Day 044 - Longest Balanced Substring II

**Date:** February 13, 2026  
**LeetCode #:** 3525  
**Difficulty:** Medium  
**Link:** [Longest Balanced Substring II](https://leetcode.com/problems/longest-balanced-substring-ii/)

---

## Problem Description

Given a string `s` consisting only of characters 'a', 'b', and 'c', find the length of the longest **balanced** substring where:
- Either all three characters appear the same number of times, OR
- Any subset of characters appears with equal frequency

### Example 1:
```
Input: s = "aabbcc"
Output: 6
Explanation: All characters appear exactly 2 times.
```

### Example 2:
```
Input: s = "aabc"
Output: 2
Explanation: "ab" or "bc" are balanced with each character appearing once.
```

---

## Solution Approach

### Method: Prefix Sum with State Hashing

The algorithm uses prefix sums and state hashing to find balanced substrings:

1. **Prefix Sum Array:** Track cumulative counts of 'a', 'b', 'c'
   - `p[i] = [count_a, count_b, count_c]` up to index i

2. **State Keys:** Generate keys representing different balance conditions:
   - `(a-b, a-c)` - All three characters equal
   - `(a-b, c)` - Only 'a' and 'b' balanced
   - `(b-c, a)` - Only 'b' and 'c' balanced
   - `(c-a, b)` - Only 'a' and 'c' balanced
   - Single character states for substrings with one character

3. **Hash Map:** Store first occurrence of each state
   - When same state reappears, the substring between is balanced

### Time Complexity
- **O(n)** - Single pass through string with O(1) state lookups

### Space Complexity
- **O(n)** - Hash map storing states
