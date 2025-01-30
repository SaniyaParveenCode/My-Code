class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int count = 0;
        vector<int>prefixsum(n , 0);
        // to store index of candles in string
        vector<int>cp;
        vector<int>ans;

        for(int i=0;i<n;i++) {
            if(s[i]=='*') 
            count++;
            if(s[i]=='|')
            cp.push_back(i);
            prefixsum[i] = count;
            // This runs for every `i`, regardless of `s[i]`
        }
        for(int i=0;i<queries.size();i++) {
            int l = lower_bound(cp.begin() , cp.end() ,  queries[i][0]) - cp.begin();
            int r = upper_bound(cp.begin(),cp.end(), queries[i][1])-cp.begin();
            if (l >= cp.size() || r <= 0 || r > cp.size() || prefixsum[cp[r-1]] - prefixsum[cp[l]] < 0)

            ans.push_back(0);
            else ans.push_back(prefixsum[cp[r-1]]-prefixsum[cp[l]]);
      }
      return ans;  
    }
};


        