class Solution {
public:
int solve(int i ,int j ,  string &s , vector<vector<int>>&dp) {
if( i> j) return 0;
if(i==j) return 1;
if(dp[i][j] != -1) return dp[i][j];
if(s[i] == s[j])
return 2+ solve(i+1 , j-1 , s , dp);
else 
return  dp[i][j] = max(solve(i+1 , j , s , dp) , solve(i , j-1 , s , dp));
}
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n , vector<int>(n, -1));
        return solve(0 ,s.size() -1  ,s , dp);
    }
};