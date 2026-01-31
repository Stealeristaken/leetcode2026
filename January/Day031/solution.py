class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        i=0
        j=len(letters)-1
        if(target>=letters[-1] or target<letters[0]):
            return letters[0]
        while i<=j:
            mid = (i+j) //2
            if(letters[mid]>target):
                j=mid-1
            elif (letters[mid]<=target):
                i=mid+1
            
        return letters[i]