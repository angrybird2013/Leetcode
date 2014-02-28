class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> map(m, vector<int>(n));
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i==m-1 && j==n-1) {
                    map[i][j] = grid[i][j];
                } else if(i==m-1) {
                    map[i][j] = grid[i][j] + map[i][j+1];
                } else if(j==n-1) {
                    map[i][j] = grid[i][j] + map[i+1][j];
                } else {
                    map[i][j] = grid[i][j] + (map[i+1][j]>map[i][j+1]?map[i][j+1]:map[i+1][j]);
                }
            }
        }
        return map[0][0];
    }
};