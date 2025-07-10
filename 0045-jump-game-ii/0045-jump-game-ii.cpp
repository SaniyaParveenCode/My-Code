class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int jumpEnd =0;
        int farthestReach = 0;

        for(int i = 0;i<n-1;i++) {
            farthestReach = max(farthestReach , i+ nums[i]);

            if(i==jumpEnd){
            jumps++;
            jumpEnd = farthestReach;
        }
        }
    return jumps;
}
};