class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
		// Stores the index of the candle present to the left of the current index
        vector<int> left(n, -1);
		// Stores the index of the candle present to the right of the current index
        vector<int> right(n, -1);
		// Prefix sum of plates
        vector<int> count(n, 0);
        
		count[0] = (s.front() == '*' ? 1 : 0);
        left[0] = (s.front() == '|' ? 0 : -1);
        right[n-1] = (s.back() == '|' ? n-1 : -1);
        
        int start = 1, end = n-2;
        
		// Calculating indices and prefix sum
        while(start < n){
            count[start] = (s[start] == '*' ? 1 : 0) + count[start-1];
            left[start] = (s[start] == '|' ? start : left[start-1]);
            right[end] = (s[end] == '|' ? end : right[end+1]);    
            start++;
            end--;
        }
        
        vector<int> ans;
        for(auto it: queries){
            int l = right[it[0]], r = left[it[1]];
			
			// No proper candle boundaries
            if(l == -1 || r == -1 || l >= r){
                ans.push_back(0);
            }
            else{
                ans.push_back(count[r]-count[l]);
            }
        }
        
        return ans;
    }
};