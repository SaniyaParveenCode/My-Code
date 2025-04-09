class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int , int>mp;   
        for(int i : nums) {
            if(i < k) return -1;
            mp[i]++;
            if(i != k && mp[i] == 1) {
                count++;
            }  
        }
        return count;
    }
};