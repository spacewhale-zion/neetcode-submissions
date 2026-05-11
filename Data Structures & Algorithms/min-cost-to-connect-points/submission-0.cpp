class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for (int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for (int j=0;j<n;j++){
                if (i==j)continue;
                int x2=points[j][0];
                int y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist});
            }

        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(n,0);
        int ans=0;
        while (!pq.empty()){

            auto [d,node]=pq.top();
            pq.pop();
           

            if (vis[node])continue;
             ans+=d;
            vis[node]=1;

            for (auto p:adj[node]){
                auto [v,dist]=p;
                if (!vis[v])pq.push({dist,v});
                
            }

        }
        return ans;
    }
};
