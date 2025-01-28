class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int mod = 1e9+7;
        vector<int> freq(nums.size(), 0);

        // Populate the frequency array
        for (const auto& req : requests) {
            freq[req[0]]++;
            if (req[1] + 1 < freq.size()) {
                freq[req[1] + 1]--;
            }
        }

        // Compute prefix sums for the frequency array
        for (int i = 1; i < freq.size(); i++) {
            freq[i] += freq[i - 1];
        }

        // Sort the frequency array and the nums array
        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        long long sum = 0;  

        // Calculate the maximum sum
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + 1LL * nums[i] * freq[i]) % mod;
        }

        return sum % mod;
    }
};
