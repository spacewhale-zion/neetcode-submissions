
class DSU{
    public:
    vector<int>par,rnk;
    DSU(int n){
        par.assign(n,0);
        rnk.assign(n,0);
        for(int i=0;i<n;i++)par[i]=i;
    }
    int find(int u){
        if (par[u]==u)return u;
        return par[u]=find(par[u]);
    }

    void unite(int u,int v){
        int up=find(u);
        int vp=find(v);
        if (up==vp)return;

        if (rnk[up]>rnk[vp]){
            par[vp]=up;\
        }
        else if (rnk[vp]>rnk[up]){
            par[up]=vp;
        }
        else {
            par[up]=vp;
            rnk[vp]+=1;
        }

    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>ans;
        int n=edges.size();
        DSU ds(n+1);
        for(auto e:edges ){
            int u=e[0];
            int v=e[1];

            if (ds.find(u)==ds.find(v))ans.push_back(e);

            else ds.unite(u,v);
        }
        return ans.back();
    }
};
