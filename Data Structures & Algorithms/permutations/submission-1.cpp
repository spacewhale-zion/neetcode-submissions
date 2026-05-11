class Solution {
public:
vector<vector<int>>ans;
    void solve(int ind,vector<int>&temp,int n,vector<int>& nums,set<int>&st){
        
       if (ind>=n){
         ans.push_back(temp);
         return;
       } 

      
      for (int i=0;i<n;i++){
         int t=temp[ind];
         if (st.find(nums[i])!=st.end()){
           temp[ind]=nums[i];
           st.erase(nums[i]);
          solve(ind+1,temp,n,nums,st);
          st.insert(nums[i]);

         }
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n,0);
        set<int>st;
        for(auto e:nums)st.insert(e);
        solve(0,temp,n,nums,st);
         return ans;

    }
};

