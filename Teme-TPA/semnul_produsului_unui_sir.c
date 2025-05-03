#include <stdio.h>
#include <stdlib.h>

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
            break;
        k1++;
    }
    if(nums[i]==0&&i<numsSize)
        return 0;
    if(k1%2==0)
        return 1;
    else
        return -1;
}
int main(void)
{   
    FILE *fis=NULL;
    int n=0,*v=NULL;
    fis=fopen("semnul_produs.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    fscanf(fis,"%d",&n);
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL)
    {
        perror("eorare la alocarea dinamica\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fis,"%d",&v[i]);
    }
    printf("%d\n",arraySign(v,n));

    return 0;
}