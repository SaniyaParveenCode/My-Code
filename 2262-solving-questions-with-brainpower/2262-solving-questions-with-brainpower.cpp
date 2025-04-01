class Solution {
public:
    long long int solve(int idx,vector<long long int>&dp,vector<vector<int>>& questions){
        if(idx>=questions.size() )
            return 0;


        if(dp[idx]!=-1)
        return dp[idx];

        long long  take=questions[idx][0]+solve(idx+questions[idx][1]+1,dp,questions);
        long long nottake=solve(idx+1,dp,questions);

        return dp[idx]=max(take,nottake);
        
        }   
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long int>dp(n,-1);
        return solve(0,dp,questions);
         
    }
};