class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int curr = 0;
        int maxLen = 0;

        for(int right = 0;right<n;right++) {
            while((curr & nums[right]) != 0) {
                curr ^= nums[left];
                left++;
            }
            curr |= nums[right];
            maxLen = max(maxLen , right- left +1);
        }
        return maxLen;
    }
};