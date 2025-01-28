class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int sum = 0, maxi = 0, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
            while (mpp[nums[i]] > 1) {
                sum -= nums[left];
                mpp[nums[left]]--;
                left++;
            }
            sum += nums[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};