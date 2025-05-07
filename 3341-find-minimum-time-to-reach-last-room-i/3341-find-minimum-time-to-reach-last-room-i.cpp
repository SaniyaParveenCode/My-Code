class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size(); 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;
        pq.push({0, {0, 0}}); 
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        while(!pq.empty()){
            auto [currTime, pos] = pq.top();
            pq.pop();
            int r = pos.first;
            int c = pos.second; 
            if(currTime > minTime[r][c])continue; 
            if(r == n - 1 && c == m - 1) return currTime; 
            for(auto& dir : directions){
                int newr = r + dir.first;
                int newc = c + dir.second; 
                if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                    int waitTime = max(0, moveTime[newr][newc] - currTime);
                    int newTime = currTime + waitTime + 1; 
                    if(newTime < minTime[newr][newc]){
                        minTime[newr][newc] = newTime;
                        pq.push({newTime, {newr, newc}});
                    }
                }
            }
        } 
        return -1;  
    }
};