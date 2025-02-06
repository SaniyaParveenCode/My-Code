class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuple = 0;
        unordered_map<int , int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++) 
            {
                int p = nums[i] * nums[j];
                mp[p]++;
            }
        }
        for(auto &it : mp) {
            int prod = it.first;
            int freq = it.second;
            tuple += (freq * (freq-1))/2;
        }
        return tuple * 8;
    }
};

                