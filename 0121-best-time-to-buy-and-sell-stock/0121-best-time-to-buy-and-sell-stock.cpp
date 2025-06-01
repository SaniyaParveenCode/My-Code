class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int min_ = prices[0];
        int profit = 0;

        for(int i = 1;i<prices.size();i++) {
            profit = max(prices[i] - min_ , profit);
            min_ = min(min_, prices[i]);
        }
        return profit;
    }
};