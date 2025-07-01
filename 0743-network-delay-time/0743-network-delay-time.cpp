class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            pair<int, int> top = pq.top(); pq.pop();
            int dis = top.first;
            int node = top.second;

            for (const auto& edge : adj[node]) {
                int adjNode = edge.first;
                int edW = edge.second;

                if (dist[adjNode] > dis + edW) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxDist = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9) return -1;
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};
