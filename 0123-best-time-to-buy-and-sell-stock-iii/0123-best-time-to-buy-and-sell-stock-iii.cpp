class Solution {
public:
    int solve(int day, vector<int>& prices, int transactionsLeft) {
        //  No days left or no transactions left
        if (day == prices.size() || transactionsLeft == 0) {
            return 0;
        }

        // No transaction today
        int ans1 = solve(day + 1, prices, transactionsLeft);

        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0); // Even transactionsLeft means we can buy

        if (buy) {
            // Buy stock
            ans2 = -prices[day] + solve(day + 1, prices, transactionsLeft - 1);
        } else {
            // Sell stock
            ans2 = prices[day] + solve(day + 1, prices, transactionsLeft - 1);
        }

        return max(ans1, ans2); // Return the maximum profit
    }

    int maxProfit(vector<int>& prices) {
        return solve(0, prices, 4); // Start from day 0 with 4 transactions allowed
    }
};
