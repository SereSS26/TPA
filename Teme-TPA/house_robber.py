class Solution(object):
    def rob(self, nums):
        k=0
        if(len(nums)==1):
            return nums[0]
        if(len(nums)==2):
            if(nums[0]>=nums[1]):
                return nums[0]
            else:
                return nums[1]
        nums[1]=max(nums[0],nums[1])
        for i in range(2,len(nums)):
            nums[i]=max(nums[i-2]+nums[i],nums[i-1])
        return nums[len(nums)-1]