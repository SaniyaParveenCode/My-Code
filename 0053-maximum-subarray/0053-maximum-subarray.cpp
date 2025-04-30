class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int Max_So_Far = nums[0];
        int curr_Max = nums[0];

        for(int i = 1;i<n;i++) {
            curr_Max = max(nums[i] , nums[i]+ curr_Max);
            Max_So_Far = max(curr_Max , Max_So_Far);
        }
        return   Max_So_Far;
    }
};