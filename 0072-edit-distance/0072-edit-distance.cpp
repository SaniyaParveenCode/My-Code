class Solution {
public:
    int solve(string &s1, string &s2, int m, int n, vector<vector<int>> &dp) {
        if(m==0) return n;
        if(n==0) return n=m;
         
        if(dp[m][n] != -1) return dp[m][n];

        if(s1[m -1] == s2[n-1]) {
             dp[m][n] = solve(s1, s2, m-1,n-1,dp);
        }
      else {
          dp[m][n] = 1+  min({
            solve(s1, s2, m-1,n-1, dp),   // replace
            solve(s1,s2,m-1,n,dp),  // delete
            solve(s1,s2,m,n-1,dp)} // insert
      );
      }
      return dp[m][n];
    }
    int minDistance(string word1, string word2) {

     int m = word1.size();
     int n = word2.size();  
     vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1)); 
      return solve(word1,word2, m,n,dp);
      
       }
};
