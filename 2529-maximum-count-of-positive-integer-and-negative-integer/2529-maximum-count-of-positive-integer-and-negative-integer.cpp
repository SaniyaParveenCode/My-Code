class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int poscount = 0;
        int negcount = 0;
        int maxi_ = INT_MIN;


        for(int i = 0;i<n;i++) {
        if(nums[i] < 0) 
        {
            negcount++;
        }
        else if( nums[i] > 0) {
        poscount++;
        }
        
       
       maxi_ =   max( negcount , poscount);
        }
        return maxi_;
    
    }
};