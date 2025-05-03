int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int rob(int* nums, int numsSize) 
{   
    if(numsSize==1)
        return nums[0];
    if(numsSize==2)
    {
        if(nums[0]<nums[1])
            return nums[1];
        else
            return nums[0]; 
    }
    nums[1]=max(nums[0],nums[1]);
    for(int i=2;i<numsSize;i++)
    {
        nums[i]=max(nums[i-2]+nums[i],nums[i-1]);
    }
    return nums[numsSize-1];
}