int min(int a,int b)
{
    if(a<=b)
        return a;
    else
        return b;
}
int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int n=gridSize;
    int m=*gridColSize;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {   
            if(i<n-1&&j<m-1)
            {
                grid[i][j]=grid[i][j]+min(grid[i+1][j],grid[i][j+1]);
            } 
            else if(i<n-1) 
            {
                grid[i][j]=grid[i][j]+grid[i+1][j];
            } 
            else if(j<m-1)
            {
                grid[i][j]=grid[i][j]+grid[i][j+1];
            }
        }
    }
    return grid[0][0];
}