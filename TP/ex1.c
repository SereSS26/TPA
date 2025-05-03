#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20

int main(void)
{       
    int a[3][3],i=0,j=0,n=0;
    int *p=NULL;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = i * n + j + 1; // Sau puteți citi valori cu scanf() dacă doriți
        }
    }
    j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    for(p=&a[0][0];p<&a[n][0];p=p+n+1)
    {
        printf("%d\n",*p);
    }
    
    return 0;
}