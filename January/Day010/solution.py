class Solution:
    def minimumDeleteSum(self, s: str, t: str) -> int:
        @cache
        def f(i,j):
            if i==len(s) or j==len(t): return sum(map(ord,s[i:]+t[j:]))
            return f(i+1,j+1) if s[i]==t[j] else min(ord(s[i])+f(i+1,j),ord(t[j])+f(i,j+1))
            
        return f(0,0)