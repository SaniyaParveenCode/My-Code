class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> mp;

       
        mp[0] = 1;

        for (int num : nums) {
            sum += num;

            int remainder = (sum % k + k) % k;

            if (mp.find(remainder) != mp.end()) {
                count += mp[remainder];
            }

            mp[remainder]++;
        }

        return count;
    }
};
