class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>>ans(n , vector<int>(n , 1));
       int left = 0 , right = n-1 , top = 0, bottom = n-1 , index = 1;

       while( left <= right && top<=bottom) {

        // first row
        for(int i = left; i<= right;i++) {
            ans[top][i] = index;
            index++;
        }
        top++;

        for(int p = top;p<= bottom;p++) {
            ans[p][right] = index;
            index++;
        }
        right--;

        // last row
        for(int j = right;j>=left;j--) {
            ans[bottom][j] = index;
            index++;
        }
        bottom--;
 
        // first col
        for(int k = bottom ; k>= top;k--) {
            ans[k][left] = index;
            index++;
        }
        left++;
       }
       return ans;
    }
};