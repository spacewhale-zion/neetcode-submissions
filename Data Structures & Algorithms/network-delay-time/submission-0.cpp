class Solution {
public:

    int distra(vector<vector<pair<int,int>>>&adj,int k){

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=adj.size();
        pq.push({0,k});
        vector<int>dist(n,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){

            auto [d,node]=pq.top();
            pq.pop();

            for (auto p:adj[node]){
                auto [v,t]=p;

                if (dist[v] > t+dist[node]){
                    dist[v]=t+dist[node];
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for (int i=1;i<n;i++){
            if (dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);

        }
        return ans;

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for (auto vec:times){
            int u=vec[0];
            int v=vec[1];
            int t=vec[2];
            adj[u].push_back({v,t});
        }
        return distra(adj,k);
    }
};
