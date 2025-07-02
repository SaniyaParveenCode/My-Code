class Solution {
public:
const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
    using ll = long long;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        vector<vector<pair<int , int>>>adj(n);
        // Builiding adjacency list
        for(auto& road: roads) {
            int from = road[0];
            int to = road[1];
            int time = road[2];

            adj[from].push_back({to , time});
            adj[to].push_back({from , time});
        }
        
        vector<ll>dist(n , LLONG_MAX);
        vector<ll>ways(n,0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()) {
            auto[d,u] = pq.top();
            pq.pop();

            if(d>dist[u]) continue;

            for(auto&[v,w]:adj[u]) {
                if(dist[v]>d+w){
                    dist[v]=d+w;
                    ways[v]=ways[u];
                    pq.push({dist[v],v});
                }else if(dist[v]==d+w){
                    ways[v]=(ways[v]+ways[u])% MOD;
                }
            }
        }
        return ways[n-1];
    }
};