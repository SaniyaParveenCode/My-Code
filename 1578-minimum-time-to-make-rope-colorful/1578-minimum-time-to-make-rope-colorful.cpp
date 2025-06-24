class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int n = colors.size();
        int maxTime = neededTime[0];
        for(int i =1;i<n;i++) {
            if(colors[i] == colors[i-1]) {
            totalTime += min(neededTime[i], maxTime);
            maxTime = max(neededTime[i], maxTime);
            }
    else {
maxTime = neededTime[i];
    }   
    }
    return totalTime; 
    }
};