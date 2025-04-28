class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0,sum=0;
        int i=-1,l=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(l<=j && (j-i)*(sum)>=k){
             sum-=nums[l];
             i=l;
             l++;
            }
            ans=ans+(long long)(j-i);
        }
        return ans;
    }
};