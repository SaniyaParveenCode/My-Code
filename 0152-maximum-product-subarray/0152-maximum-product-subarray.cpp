class Solution {
public:
int maxProduct(vector<int>& nums) 
{
int n = nums.size();
int leftp = 1;
int rightp = 1;
int ans = INT_MIN;
    for(int i = 0;i<n;i++) {
        if(leftp == 0)
        leftp = 1;
        if(rightp == 0) 
        rightp = 1;

        leftp *= nums[i];
        rightp *= nums[n - 1 - i];
        ans = max(ans ,max (leftp  , rightp));
    }
    return  ans;
    }
};

// Time Complexity:O(n)
// Space Complexity:O(1)