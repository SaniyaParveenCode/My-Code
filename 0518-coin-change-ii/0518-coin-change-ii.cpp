class Solution {
public:
int changecoin(int i , int amount , vector<int>&coins , vector<vector<int>>&dp) {
    if(amount == 0) return 1;
    if(i==coins.size() || amount < 0 ) return 0;
    if(dp[i][amount] != -1) return dp[i][amount];

    int include  = 0;
    if(coins[i] <= amount) {
        include =  changecoin( i , amount - coins[i] , coins , dp);
    }
int  exclude = changecoin(i+1 , amount , coins , dp);
return dp[i][amount] = include + exclude;
}
int change(int amount, vector<int>& coins) {
vector<vector<int>>dp(coins.size() , vector<int>(amount+1 , -1));
return changecoin(0 , amount , coins , dp);
}
};
