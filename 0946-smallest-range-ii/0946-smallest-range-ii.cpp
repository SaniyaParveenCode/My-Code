class Solution {
public:
int smallestRangeII(vector<int>& nums, int k) {
int n = nums.size();
sort(nums.begin() , nums.end());
int min_ = INT_MAX;
int max_ = INT_MIN;
int res = nums[n-1] - nums[0];
int bestL = nums[0]+k;
int bestR = nums[(n-1)]-k;


for(int i=0;i<n-1;i++) {
    int max_ = max(nums[n-1] - k, nums[i] +k); 
    int min_ = min(nums[0] + k, nums[i+1] - k);
    res = min(res , max_ - min_);
}
return res;

}
};
