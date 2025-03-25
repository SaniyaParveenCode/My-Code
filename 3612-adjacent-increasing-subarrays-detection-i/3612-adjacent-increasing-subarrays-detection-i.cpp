class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n / k < 2) return false;
        if(k == 1) return true;
        vector<int> vis(n,0);
        int start = 0,end = 1;
        while(end < n){
            while(end < n and nums[end] > nums[end - 1]){
                if(end - start + 1 == k){
                    vis[start] = 1;
                    start++;
                }
                end++;
            }
            start = end;
            end++;
        }

        for(int i = 0;i<=n - (2 * k);i++){
            if(vis[i] and vis[i + k])return true;
        }
        return false;
    }
};