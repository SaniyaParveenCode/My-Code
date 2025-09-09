class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> x, y;

        // Collect rows and columns to be zeroed
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        // Set rows to zero
        for(int i = 0; i < x.size(); i++) {
            int row = x[i];
            for(int j = 0; j < m; j++) {
                matrix[row][j] = 0;
            }
        }

        // Set columns to zero
        for(int i = 0; i < y.size(); i++) {
            int col = y[i];
            for(int j = 0; j < n; j++) {
                matrix[j][col] = 0;
            }
        }
    }
};
