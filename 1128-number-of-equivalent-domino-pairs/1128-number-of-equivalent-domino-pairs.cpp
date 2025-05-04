class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int , int>mp;
        int count = 0;
        for(auto& x: dominoes) {
            int a = min(x[0] , x[1]);
            int b = max(x[0] , x[1]);
            int key = a * 10 + b;
            count+= mp[key];
            mp[key]++;
        }
        return count;
    }
};