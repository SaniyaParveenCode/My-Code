class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                ans[i][j] = getMaxValueAcross3x3Grid(grid, i, j);
            }
        }
        return ans;
    }

private:
    int getMaxValueAcross3x3Grid(vector<vector<int>>& grid, int row, int col) {
        int maxVal = 0;

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                maxVal = max(maxVal, grid[i][j]);
            }
        }
        return maxVal;
    }
};
