class Solution {
    public:
    int fibHelp(int n , vector<int>&dp) {
        if(n==0 || n==1) 
        return n;

        if(dp[n] != -1) 
            return dp[n];
    
          dp[n] =  fibHelp(n-1 , dp) + fibHelp(n-2 , dp);
          return dp[n];
    }
    int fib(int n ) {
            vector<int>dp(n+1  , -1);
            return fibHelp( n,dp);
    }
};