class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int a , b;
      int n = nums.size();
      unordered_map<int , int>mp;
      for(int a = 0;a<n;a++) {
        b = target - nums[a];

        if(mp.find(b) != mp.end()) 
        {
            return {mp[b] , a};
        }
        mp[nums[a]] = a;
      }
      return {};

    }
};
