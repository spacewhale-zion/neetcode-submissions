class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& nv) {
        
        v.push_back(nv);
        sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>>ans;
        ans.push_back(v[0]);

        for(int i=1;i<n;i++){

            int px=ans.back()[0];
            int py=ans.back()[1];

            if (py>= v[i][0]){

                ans.back()[0]=min(px,v[i][0]);
                ans.back()[1]=max(py,v[i][1]);
            }
            else{
                ans.push_back(v[i]);
            }

        }
        return ans;

         }
};
