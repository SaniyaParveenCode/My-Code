// class Solution {
//     public:

//     int coinChange(vector<int>&coins , int amount) {
//         vector<int>dp(amount+1 , INT_MAX);
//         dp[0] = 0;
//         for(int amt=1;amt<=amount;amt++)
//         {
//             for(int coin : coins) {
//                 if(amt-coin >=0 & dp[amt-coin] != INT_MAX) {
//                     dp[amt] = min(dp[amt] , dp[amt - coin] + 1);
//                 }
//              }
//         }
//         return dp[amount]==INT_MAX? -1: dp[amount];
//     }
// };
class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0; 
        if (amount < 0) return INT_MAX; 

        if (dp[amount] != -1) return dp[amount]; 

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = solve(coins, amount - coin, dp);
            if (res != INT_MAX) {
                minCoins = min(minCoins, res + 1);
            }
        }

        dp[amount] = minCoins; 
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1); 
        int result = solve(coins, amount, dp);
        return result == INT_MAX ? -1 : result; 
    }
};

