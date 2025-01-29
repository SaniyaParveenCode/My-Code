class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        if(n==0 || n==1 )
        return 0;
        
        int max_ = nums[n-1];
        int min_ = nums[0];
        int res = max_ -min_;

        for(int i=1;i<n;i++) {
            max_ = max(nums[i-1] + k , nums[n-1] - k);
            min_ = min(nums[i] - k , nums[0] + k);
            res = min(res , max_ - min_);
        }
        return res;
    }
};