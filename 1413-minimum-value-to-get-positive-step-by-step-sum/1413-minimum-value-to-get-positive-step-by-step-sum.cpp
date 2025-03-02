class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int minimum = INT_MAX;
        for(int i=0;i<n;i++) {
           sum = sum + nums[i];
           minimum = min(minimum , sum);

        }
        return max(1,1-minimum);
    }
};

