int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int f1(int *nums,int numsSize)
{
    int *v=NULL;
    v=(int*)malloc((numsSize-1)*sizeof(int));
    if(v==NULL)
    {
        exit(-1);
    }
    for(int i=0;i<numsSize-1;i++)
        v[i]=nums[i];
    v[1]=max(v[0],v[1]);
    for(int i=2;i<numsSize-1;i++)
    {
        v[i]=max(v[i-2]+v[i],v[i-1]);
    }
    int r=v[numsSize-2];
    free(v);
    return r;
}
int f2(int *nums,int numsSize)
{
    int *v=NULL;
    v=(int*)malloc((numsSize-1)*sizeof(int));
    if(v==NULL)
    {
        exit(-1);
    }
    for(int i=0;i<numsSize-1;i++)
    {
        v[i]=nums[numsSize-1-i];
    }
    v[1]=max(v[0],v[1]);
    for(int i=2;i<numsSize-1;i++)
    {
        v[i]=max(v[i-2]+v[i],v[i-1]);
    }
    int r=v[numsSize-2];
    free(v);
    return r;
}
int rob(int* nums, int numsSize)
{
    if(numsSize==1)
        return nums[0];
    if(numsSize==2)
    {
        if(nums[1]>=nums[0])
            return nums[1];
        else
            return nums[0];
    } 
    return max(f1(nums,numsSize),f2(nums,numsSize));   
}