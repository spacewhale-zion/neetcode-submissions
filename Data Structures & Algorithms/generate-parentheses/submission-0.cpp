class Solution {
public:
    vector<string>ans;
    void solve(int ind,int l,int r,string s,int n){

        if (ind>=2*n){
            ans.push_back(s);
            return;
        }
        if (l<n){
            s[ind]='(';
            solve(ind+1,l+1,r,s,n);
            s[ind]='.';
        }
        if (r<l){
            s[ind]=')';
            solve(ind+1,l,r+1,s,n);
            s[ind]='.';
        }


    }
    vector<string> generateParenthesis(int n) {
        string s="";
        for (int i=0;i<2*n;i++)s+='.';
        solve(0,0,0,s,n);
        return ans;
    }
};
