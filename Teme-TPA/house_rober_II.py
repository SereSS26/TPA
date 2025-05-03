def f1(nums):
    if(len(nums)==1):
        return nums[0]
    if(len(nums)==2):
        return max(nums[0],nums[1])
    v=[0]*len(nums)
    v[0]=nums[0]
    v[1]=max(nums[0],nums[1])
    for i in range(2,len(nums)):
        v[i]=max(v[i-2]+nums[i],v[i-1])
    return v [-1]
class Solution(object):
    def rob(self, nums):
        if(len(nums)==1):
            return nums[0]
        if(len(nums)==2):
            return max(nums[0],nums[1])
        return max(f1(nums[:-1]),f1(nums[1:]))