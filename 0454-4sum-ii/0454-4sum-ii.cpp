class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int> m;

        // Compute sums of pairs from A and B, and store in the map
        for (int a : A) 
            for (int b : B) 
                m[a + b]++;

        // Compute sums of pairs from C and D, and check against the map
        for (int c : C) 
            for (int d : D) 
                ans += m[-(c + d)];

        return ans;
    }
};
