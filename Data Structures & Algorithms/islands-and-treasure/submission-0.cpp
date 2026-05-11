class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        // int max=2147483647;
        queue<vector<int>>q;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0)q.push({i,j,0});
            }
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        while (!q.empty()){

            int p=q.size();
            for(int i=0;i<p;i++){

                int r=q.front()[0],c=q.front()[1],dist=q.front()[2];
                q.pop();
                for (int j=0;j<4;j++){
                    int nr=r+dr[j];
                    int nc=c+dc[j];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=-1 && grid[nr][nc]>dist+1){
                        q.push({nr,nc,dist+1});
                        grid[nr][nc]=dist+1;
                    }

                }
            }
        }
    }
};
