class Solution {
public:
    bool iscycle(vector<vector<int>>&adj,vector<int>&vis,int node,int par){

        vis[node]=1;
        for (auto v:adj[node]){
            if (v==par)continue;

              if (!vis[v]) {

                if (iscycle(adj, vis, v, node))
                    return true;
            }

            else return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {

         if(edges.size()!=n-1)return false;
         
         vector<vector<int>>adj(n);

         for (int i=0;i<n-1;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
         }
         vector<int>vis(n,0);
         bool cycle=iscycle(adj,vis,0,-1);
         if (cycle)return false;
         for (int i=0;i<n;i++)if (vis[i]==0)return false;
         cout<<cycle<<"\n";
         return true;
    }
};
