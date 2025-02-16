class Solution {
    public:
    int minCost(vector<int>& cost , int n) {
        if(n<=1)
        return 0;
        if(n==2)
        return min(cost[0] , cost[1]);

        return min(minCost(cost , n-1) + cost[n-1] , minCost(cost , n-2) + cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(1000 , 1);
        return minCost(cost , n);
    }
};