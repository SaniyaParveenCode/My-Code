class Solution {
public:
   int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        for(int i= 0;i<n;i++) {
            sort(grid[i].begin() , grid[i].end()) ;
            ans += lower_bound(grid[i].begin() , grid[i].end() , 0) - grid[i].begin();

        }
        return ans;
   }
};
