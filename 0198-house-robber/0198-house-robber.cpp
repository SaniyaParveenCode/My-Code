vector<int>dp(101 , -1);
class Solution {
public:
int robhouse(vector<int>&nums , int n) {
if(n<=0) return 0;
if(dp[n] != -1) return dp[n];

return dp[n] = max
(
    robhouse(nums, n-1)  ,
     robhouse(nums , n-2) + nums[n-1]);

}
    int rob(vector<int>&nums) {
        int n = nums.size();
        fill(dp.begin() , dp.end() , -1);
        return robhouse(nums , n);
    }
};
        

        


