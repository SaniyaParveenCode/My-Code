class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> result(2, vector<int>(n, 0)); // Initialize a 2 x n matrix with zeros
        
        // Iterate through each column
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                // If colsum[i] is 2, assign 1 to both rows
                if (upper > 0 && lower > 0) {
                    result[0][i] = 1;
                    result[1][i] = 1;
                    upper--;
                    lower--;
                } else {
                    return {}; // Invalid case
                }
            } else if (colsum[i] == 1) {
                // If colsum[i] is 1, assign 1 to the row with remaining sum
                if (upper >= lower && upper > 0) {
                    result[0][i] = 1;
                    upper--;
                } else if (lower > 0) {
                    result[1][i] = 1;
                    lower--;
                } else {
                    return {}; // Invalid case
                }
            }
            // If colsum[i] == 0, both rows remain 0 (default in result)
        }
        
        // Check if all upper and lower sums are used
        if (upper == 0 && lower == 0) {
            return result;
        }

        return {}; // Return empty matrix if not all sums are used
    }
};
