vector<int>dp(1001 , -1);
class Solution {
    public:
    int minCost(int n , vector<int>&cost ) {
        if(n<=1 ) return dp[n] = 0;
        if(n==2) return dp[n] = min(cost[0] , cost[1]);
        if(dp[n] != -1) return dp[n];

       return dp[n] =  min (
            minCost(n-1 , cost ) + cost[n-1] ,
            minCost(n-2 ,cost) + cost[n-2]);
    
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    fill(dp.begin() , dp.end() , -1);
    return minCost(n, cost);
    }
};