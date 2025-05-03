int compara(const void *a,const void *b)
{
    const int *x=(const int*)a;
    const int *y=(const int*)b;
    return (*x)-(*y);
}
int arraySign(int* nums, int numsSize) 
{
    int i=0,k1=0;
    qsort(nums,numsSize,sizeof(int),compara);
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>=0)
        {
            if(nums[i]==0)
                return 0;
            break;
        }
        k1++;
    }
    if(k1%2==0)
        return 1;
    else
        return -1;
}