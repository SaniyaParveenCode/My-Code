class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
       vector<vector<int>> ans(m , vector<int>(n));

       if(m *n != original.size()) {
        return {};
       }

       for(int i = 0;i<original.size();i++) {
        ans[i / n][i % n] = original[i];
       }
       return ans;
    }
};