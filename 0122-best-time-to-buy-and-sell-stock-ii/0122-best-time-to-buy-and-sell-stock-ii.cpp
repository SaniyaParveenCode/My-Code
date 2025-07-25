class Solution
{
public:
int solve(int i ,int canBuy, vector<int>& prices, vector<vector<int>>&dp){
    if(i == prices.size()) return 0;
    if(dp[i][canBuy] != -1) return dp[i][canBuy];

    int profit = 0;
    if(canBuy) {
        int buy = -prices[i] + solve(i+1,0 ,prices , dp) ;
        int skip = solve(i+1 , 1, prices , dp);
        profit = max(buy, skip);
    }
    else {
        int sell = prices[i] + solve(i+1 ,1 , prices , dp);
        int skip = solve(i+1 , 0, prices , dp );
        profit = max(sell, skip);
    }
    return dp[i][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2 , -1));
      return solve(0 , 1,prices , dp);
    }
};