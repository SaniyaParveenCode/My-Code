vector<int>dp(101 , -1);
class Solution {
    public:
    int solve(vector<int>&nums , int n ) {
        if(n<=0) 
        return 0;

        if(dp[n]!= -1)
        return dp[n];

        dp[n] = max(solve(nums , n-1 ) , nums[n-1] + solve(nums , n-2));
        return dp[n];
    }
    int rob(vector<int>&nums) {
        int n = nums.size();
        fill(dp.begin() , dp.end() , -1);
        return solve(nums , n );
    }
};



