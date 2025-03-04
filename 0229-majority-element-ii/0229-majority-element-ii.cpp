class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }
        
        for (auto& [key, value] : mp) {
            if (value > n / 3) {
                result.push_back(key);
            }
        }

        return result; 
    }
};
