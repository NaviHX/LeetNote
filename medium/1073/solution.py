class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        carry=0
        arr1=arr1[::-1]
        arr2=arr2[::-1]
        ans=[]
        if len(arr1)<len(arr2):
            arr1.extend([0]*(len(arr2)-len(arr1)))
        elif len(arr2)<len(arr1):
            arr2.extend([0]*(len(arr1)-len(arr2)))
        for i in range(len(arr1)):
            temp=arr1[i]+arr2[i]+carry
            if temp>=2:
                carry=1
                temp=temp-2
            elif temp==-1:
                carry=-1
                temp=1
            else:
                carry=0
            carry=carry*(-1)
            ans.append(temp)
        if(carry==-1):
            ans.extend([1,1])
        elif(carry==1):
            ans.append(1)
        ans=ans[::-1]
        while len(ans)>=2 and ans[0]==0:
            ans.pop()
        return ans
