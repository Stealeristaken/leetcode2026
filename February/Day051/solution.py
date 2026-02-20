class T:
 def __init__(s):s.C,s.P,s.p,s.s=[],0,"",""
class Solution:
 def makeLargestSpecial(_,s):
  C=T()
  for c in s:
   if c=='1':
    n=T()
    C.C.append(n)
    n.p,n.P,C=n.p+c,C,n
   else:C.s,C=C.s+c,C.P
  D=lambda n:n.p+''.join(sorted([D(c)for c in n.C],reverse=1))+n.s if n.C else n.p+n.s
  return D(C)