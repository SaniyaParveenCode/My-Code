class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int ascarr = nums[0];
        // Initialize with the first element
    
        for(int i = 1;i<n;i++) {
            // Start from the second element
            if(nums[i] > nums[i-1])
            // Add to the current ascending subarray
            {
              ascarr += nums[i]; 
            }
            else {
            // Update the maximum sum and reset the ascending subarray
                res = max(res , ascarr);
                ascarr = nums[i];
            }         
        }
        // Update the result for the last subarray
        res = max(res , ascarr);  
        return res;
    }
};