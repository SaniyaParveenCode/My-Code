vector<vector<int>>dp;
class Solution {
public:
  int func1( int ind , int amount , vector<int>&coins) {
    if(amount == 0)
    return 1;
    if(ind<0) return 0;
    if(dp[ind][amount] != -1)
    return dp[ind][amount];
    int ways = 0;
    for(int coin_amount=0;coin_amount<=amount;
        coin_amount+=coins[ind]) {
        ways += func1(ind-1 , amount - coin_amount , coins);
    }
return dp[ind][amount] = ways;
}
 int change(int amount, vector<int>& coins) {
     dp = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
    return func1(coins.size()-1 ,amount , coins);

    }
};
