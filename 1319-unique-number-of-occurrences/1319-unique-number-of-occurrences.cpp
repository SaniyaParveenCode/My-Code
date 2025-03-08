class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int>mp;
        for(int i=0;i<arr.size();i++) 
            mp[arr[i]]++;
            int n = arr.size();
            vector<int>freq(n,0);
            for(auto i:mp)
            {
                if(freq[i.second-1]==1) return false;
                else freq[i.second -1] = 1;
            }
            return true;
    }
};