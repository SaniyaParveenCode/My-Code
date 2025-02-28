class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_price = prices[0];
        int curr_profit = 0;
        int profit = 0;
        for(int i = 0;i<n;i++) {

        if(prices[i] < buy_price) 
        {
        buy_price = prices[i];
        }
        else 
        {
             curr_profit = prices[i] - buy_price;
             profit = max( curr_profit , profit);
         }
        }
    return profit;
    }
};