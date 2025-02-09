class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        unordered_map<int , int > mp;
        mp[nums[0]] = 1;

        for(int j = 1;j<n;j++) {
        int countOfNumsj = mp[nums[j] - j];

        int totalNumsBeforej = j;

        int badpairs = totalNumsBeforej - countOfNumsj;
        result += badpairs;
        mp[nums[j]- j]++;
       }
       return result;
    }
};