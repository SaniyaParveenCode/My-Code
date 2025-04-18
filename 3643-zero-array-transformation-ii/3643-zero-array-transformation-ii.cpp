class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        auto check = [&](int k) {
            vector<int> mp(n + 1, 0);
            for(int i = 0; i < k; i++) {
                mp[queries[i][0]] += queries[i][2];
                mp[queries[i][1] + 1] -= queries[i][2];
            }
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += mp[i];
                if(sum < nums[i]) return 0;
            }
            return 1;
        };

        int l = 0, h = queries.size();

        if(!check(h)) return -1;
        
        int k = -1;
        while(l <= h) {
            int mid = (l + h) / 2;
            if(check(mid)) {
                k = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return k;
    }
};