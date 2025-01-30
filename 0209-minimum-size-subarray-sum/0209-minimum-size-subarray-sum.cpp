class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
     int left=0;
     int right=0;
     int mini=INT_MAX;
     int sum=0;
     while(right<nums.size()){
        sum+=nums[right];
        while(left>=0&&sum>=target){
            mini=min(mini,right-left+1);
            sum-=nums[left];
        left++;
        }
        right++;
     }
     return mini==INT_MAX?0:mini;   
    }
};