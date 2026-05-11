class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>&dist,int r,int c){

        
        int n=matrix.size();
        int m=matrix[0].size();
        int d=1;
        for (int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            
            if (nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]==0 && matrix[nr][nc]>matrix[r][c]){
                d=max(1+dfs(matrix,dist,nr,nc),d);
            }  
            else if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[r][c]){
                d=max(d,1+dist[nr][nc]);
            }    
        } 
        dist[r][c]=d;
        return d;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>dist(n,vector<int>(m,0));
        int ans=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                
                if (dist[i][j]==0)ans=max(ans,dfs(matrix,dist,i,j));
            }
        }
        return ans;
    }
};
