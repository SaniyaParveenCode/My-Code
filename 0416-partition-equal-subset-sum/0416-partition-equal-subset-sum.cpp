class Solution {
public:

bool subsetSum(vector<int>nums , int n , int sum , vector<vector<int>>&dp) {
    if(n==0) return false;
    if(sum == 0 ) return true;
    if(dp[n][sum]!= -1) return dp[n][sum];
    if(nums[n-1] <= sum) {
        return dp[n][sum] = (subsetSum(nums , n - 1 , sum - nums[n-1]  ,dp)) || subsetSum(nums , n-1 , sum ,dp);
    }
    else {
        return  dp[n][sum]  = subsetSum(nums , n-1 , sum ,dp);
    }
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for( auto x:nums) {
            sum +=x;
        }
        if(sum %2 != 0) return false;

        sum = sum/2;
        vector<vector<int>>dp(n+1 , vector<int>(sum +1 , -1));
        return subsetSum(nums , n , sum , dp);
    }
};