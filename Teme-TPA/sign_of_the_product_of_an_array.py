class Solution(object):
    def arraySign(self, nums):
        k1=0
        for num in nums:
            if(num<0):
                k1=k1+1
            if(num==0):
                return 0
        if(k1%2==0):
            return 1
        else:
            return -1
        