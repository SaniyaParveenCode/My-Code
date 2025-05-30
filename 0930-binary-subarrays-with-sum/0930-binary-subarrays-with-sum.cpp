class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0;
        int ps = 0;
        unordered_map<int , int>mp;
        mp[0] = 1;
        for(int i = 0;i<nums.size();i++)
        {
            ps+= nums[i];
           if(mp.count(ps - goal)) {
            res+= mp[ps - goal];
           }
           mp[ps]++;
        }
        return res;
    }
};