class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int noStock = 0;           
        int holdStock = -prices[0]; 

        for (int i = 1; i < n; i++) {
            noStock = max(noStock, holdStock + prices[i]);
            holdStock = max(holdStock, noStock - prices[i]);
        }
        return noStock;
    }
};
