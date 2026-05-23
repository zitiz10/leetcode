class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // build the adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        // build the graph
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        // priority queue
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [d, u] = pq.top();// int d=pq.top().first; , int u=pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto& p : adj[u]) {
                int v = p.first;
                int w = p.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};