class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, -1), suffix(n, -1);
        
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], (long long)nums[i - 1]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], (long long)nums[i + 1]);
        }
        
        long long res = 0;
        for (int i = 1; i < n - 1; i++) {
            res = max(res, (prefix[i] - nums[i]) * suffix[i]);
        }
        
        return res;
    }
};