class Solution {
public:
    int rows, cols;

    int findMaxFish(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxFishes = 0;

        // Find max of all components
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != 0) {
                    maxFishes = max(maxFishes, dfs(i, j, grid));
                }
            }
        }
        return maxFishes;
    }

private:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        // Base case
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        int ans = grid[r][c];
        grid[r][c] = 0; // Mark as visited

        ans += dfs(r - 1, c, grid); // Up
        ans += dfs(r, c + 1, grid); // Right
        ans += dfs(r + 1, c, grid); // Down
        ans += dfs(r, c - 1, grid); // Left

        return ans;
    }
};
