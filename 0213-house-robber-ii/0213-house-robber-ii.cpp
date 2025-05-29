class Solution {
public:
    int robHelper(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start > end) return 0;  
        if (dp[start] != -1) return dp[start]; 
        dp[start] = max(robHelper(nums, start + 1, end, dp),  
                        nums[start] + robHelper(nums, start + 2, end, dp));  

        return dp[start];  
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  
        if (n == 1) return nums[0];  

        vector<int> dp1(n, -1); 
        vector<int> dp2(n, -1);  

        int case1 = robHelper(nums, 0, n - 2, dp1);
        int case2 = robHelper(nums, 1, n - 1, dp2);

        return max(case1, case2);  
    }
};
