class Solution {
public:
 int coin(int i , vector<int>&coins , int amount,vector<vector<int>>&dp ) {
    if(amount ==0) return 0;
    if(i == coins.size()) return 1e8;
     if(dp[i][amount]!=-1)return dp[i][amount];
    int include = INT_MAX;
    
    if(coins[i] <= amount) {
        include =  1 + coin( i , coins , amount - coins[i],dp);

    }
int exclude = coin( i+1 , coins , amount,dp);

return dp[i][amount]=min(include , exclude);
    }

int coinChange(vector<int>& coins, int amount) {
     vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
     int ans=coin(0,coins,amount,dp);
     if(ans>=1e8)return -1;
     return ans;
  
}
};
