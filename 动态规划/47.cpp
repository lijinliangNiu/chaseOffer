class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size(), colomn = grid[0].size();
        for(int i = 1; i < colomn; i++){
            grid[0][i] += grid[0][i - 1];
        }
        for(int i = 1; i < row; i++){
            grid[i][0] += grid[i - 1][0];
        }
        for(int i = 1; i < row; i++){
            for(int j = 1; j < colomn; j++){
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]); 
            }
        }
        return grid[row - 1][colomn - 1];
    }
};