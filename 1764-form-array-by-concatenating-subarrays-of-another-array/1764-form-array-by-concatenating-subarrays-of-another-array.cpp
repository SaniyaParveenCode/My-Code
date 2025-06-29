class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        auto it = nums.begin();
        for(auto vec: groups){
            it = search(it, nums.end(), vec.begin(), vec.end());
            if(it==nums.end()) return false;
            it += vec.size();
        }
        return true;
    }
};