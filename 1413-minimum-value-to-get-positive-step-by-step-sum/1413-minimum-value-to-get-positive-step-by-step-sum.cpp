class Solution {
public:
int minStartValue(vector<int>nums) {
    int n = nums.size();
    int mini_ = INT_MAX;
    int sum = 0;
    for(int i = 0;i<n;i++) {
        sum = sum+nums[i];
        mini_ = min(mini_ , sum);
    }
    return max(1 , 1-mini_);
}
};