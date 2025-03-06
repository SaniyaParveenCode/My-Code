class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int a : A)
            for (int b : B)
                mp[a + b]++;

        for (int c : C)
            for (int d : D)
                if (mp.count(-(c + d)))
                    ans += mp[-(c + d)];

        return ans;
    }
};
