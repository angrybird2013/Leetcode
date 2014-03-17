class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int v[m][n];
        v[m-1][n-1] = obstacleGrid[m-1][n-1]>0?0:1;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i==m-1 && j==n-1)
                    continue;
                else if(obstacleGrid[i][j] == 1)
                    v[i][j] = 0;
                else {
                    v[i][j] = i<m-1?v[i+1][j]:0;
                    v[i][j] += j<n-1?v[i][j+1]:0;
                }
            }
        }
        return v[0][0];
    }
};