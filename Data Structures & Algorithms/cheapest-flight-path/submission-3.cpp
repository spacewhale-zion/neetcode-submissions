class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<int>> adj[n];

        for (auto f : flights) {
            int u = f[0], v = f[1], w = f[2];
            adj[u].push_back({v, w});
        }

        queue<vector<int>> q;

        vector<int> dist(n, INT_MAX);

        q.push({0, src, 0});

        dist[src] = 0;

        while (!q.empty()) {

            auto cur = q.front();
            q.pop();

            int stops = cur[0];
            int node  = cur[1];
            int cost  = cur[2];

            if (stops > k)
                continue;

            for (auto it : adj[node]) {

                int v  = it[0];
                int wt = it[1];

                if (cost + wt < dist[v]) {

                    dist[v] = cost + wt;

                    q.push({stops + 1, v, dist[v]});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};