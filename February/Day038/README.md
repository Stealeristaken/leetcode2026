# Day 038 - Minimum Deletions to Make String Balanced

**Date:** February 7, 2026  
**LeetCode #:** 1653  
**Difficulty:** Medium  
**Link:** [Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)

---

## Problem Description

You are given a string `s` consisting only of characters `'a'` and `'b'`.

You can delete any number of characters in `s` to make `s` **balanced**. `s` is balanced if there is no pair of indices `(i,j)` such that `i < j` and `s[i] = 'b'` and `s[j] = 'a'`.

Return the **minimum** number of deletions needed to make `s` balanced.

### Example 1:
```
Input: s = "aababbab"
Output: 2
Explanation: Delete the characters at indices 2 and 6 ("aababbab" → "aaabbb").
```

### Example 2:
```
Input: s = "bbaaaaabb"
Output: 2
Explanation: Delete the first two characters or the last two characters.
```

### Constraints:
- `1 <= s.length <= 10^5`
- `s[i]` is `'a'` or `'b'`.

---

## Solution Approach

### Method: Greedy with Counter

The key insight is to track unmatched 'b's as we scan left to right:

### Algorithm:
1. **Track 'b' count** - When we see a 'b', increment counter
2. **Handle 'a' after 'b'** - When we see an 'a' and there are preceding 'b's:
   - We must delete either this 'a' or a preceding 'b'
   - Increment deletion count and decrement 'b' counter (virtually delete one 'b')
3. The greedy choice ensures minimum deletions

### Why it works:
- Each 'a' that comes after a 'b' creates a conflict
- We resolve each conflict by "using up" one 'b' (as if deleted)
- This is equivalent to finding minimum deletions

### Complexity:
- **Time:** O(n) - single pass through the string
- **Space:** O(1) - only two counters

---

## Code

### Python

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        a = 0  # deletion count
        b = 0  # unmatched 'b' count
        for x in s: 
            if x == 'b':
                b += 1 
            else:  # x == 'a'
                if b > 0:
                    a += 1
                    b -= 1 
        return a
```
