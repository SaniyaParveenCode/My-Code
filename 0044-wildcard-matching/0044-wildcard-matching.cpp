class Solution {
public:
int solve(int i , int j ,string &s, string &p , vector<vector<int>>&dp) {
if(j==p.size()) return i==s.size();
if (i == s.size())
 {
        while (j < p.size() && p[j] == '*') j++;
        return j == p.size();
    }
    if(dp[i][j] != -1)
    return dp[i][j];

    if(s[i] == p[j] || p[j] == '?') {
        return dp[i][j] =  solve(i+1 , j+1 , s, p,dp);       
    }
    if(p[j] == '*'){
       return dp[i][j] =  solve(i+1,j,s,p,dp) || solve(i,j+1,s,p,dp);
    }
    return false;
}

    bool isMatch(string s, string p) {
         vector<vector<int>>dp(s.size() , vector<int>(p.size() , -1));
        return solve(0,0,s,p, dp);
    }
};