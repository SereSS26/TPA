class Solution(object):
    def minPathSum(self, grid):
        n=len(grid)
        m=len(grid[0])
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                if (i<n-1 and j<m-1):
                    grid[i][j]=grid[i][j]+min(grid[i+1][j],grid[i][j+1])
                elif (i<n-1):
                    grid[i][j]=grid[i][j]+grid[i+1][j]
                elif (j<m-1):
                    grid[i][j]=grid[i][j]+grid[i][j+1]
        return grid[0][0]