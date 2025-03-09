class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int , int>mp;
        int count = 0 , sum =0;

        mp[0] = 1;

        for(int num :nums) {
            sum+=num;
            int remainder = (sum % k + k ) % k;

            if(mp.find(sum-k) != mp.end()) {
                count += mp[remainder];
            }
            mp[sum]++;
        }
        return count;

    }
};


