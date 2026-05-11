class Solution {
public:
    vector<vector<string>> ans;
    bool check(int r,int c,vector<string>&v,int n){

        for (int i=0;i<c;i++){
            if (v[r][i]=='Q')return false;
        }

        int nr=r,nc=c;
        while (nr>=0 && nc>=0){
            if (v[nr][nc]=='Q')return false;
            nr-=1;
            nc-=1;
        }
         nr=r,nc=c;
        while (nr<n && nc>=0){
            if (v[nr][nc]=='Q')return false;
            nr+=1;
            nc-=1;
        }
        return true;

    }
    void solve(vector<string>&v,int n,int ind){
         if (ind>=n){
            ans.push_back(v);
         }

         for (int i=0;i<n;i++){

            if (check(i,ind,v,n)){

                v[i][ind]='Q';
                solve(v,n,ind+1);
                v[i][ind]='.';

            }
         }

    }
    


    vector<vector<string>> solveNQueens(int n) {
        
         vector<string>v;
         for (int i=0;i<n;i++){
            string t="";
            for (int j=0;j<n;j++)t+='.';
            v.push_back(t);
         }
        //  vector<string>vis=v;
        solve(v,n,0);
        //  cout<<v[0]<<"\n";
         return ans;
    }
};
