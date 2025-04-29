class Solution {
public:
int maxProduct(vector<int>& nums) 
{
int n = nums.size();
vector<int>dp(n+1,-1);
int leftp = 1;
int rightp = 1;
int ans = INT_MIN;
if(dp[n]!=-1)
return dp[n];
for(int i=0;i<n;i++) {
 if(leftp==0) 
leftp= 1;
if(rightp==0) 
    rightp = 1;
    leftp*=  nums[i];
    rightp*= nums[n-1-i];
    ans = max(ans , max(leftp , rightp));
}
return dp[n]=ans;
}
};