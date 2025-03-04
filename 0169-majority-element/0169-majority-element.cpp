class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        for (auto& [key, value] : mp) {
            if (value > n / 2) {
                return key;
            }
        }

        return -1; 
    }
};
