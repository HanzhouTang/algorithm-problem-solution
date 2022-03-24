class Solution {
public:
    const int INF = INT_MAX / 2; 
    typedef pair<int,int> pii; 
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pii>> g(n);
        for(auto& e : highways) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        priority_queue<pair<pii,int>> q; 
        q.push({{0,discounts},0});
        vector<vector<int>> dis(n,vector<int>(discounts+1,INF));
        while(q.size()) {
            auto x = q.top(); 
            q.pop(); 
            auto [w,d] = x.first; 
            auto i = x.second; 
            w = -w; 
            if(i == n-1) {
                return w; 
            }
            if(dis[i][d] <= w) {
                continue;
            }
            dis[i][d] = w; 
            for(auto e : g[i]) {
                if(e.second + w < dis[e.first][d]) {
                    q.push({{-w-e.second,d},e.first});
                }
                if(d>0 && e.second / 2 + w < dis[e.first][d-1]) {
                    q.push({{-w-e.second/2,d-1},e.first});
                }
            }
        }
        return -1; 
        
    }
};