class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      
      bool onezero=false;
      bool morezero=false;

      int cnt=0;
      int n=nums.size();
      for (auto e:nums)if(e==0)cnt+=1;
      vector<int>ans(n,0);
      int prod=1;
      int ind =-1;
      for (int i=0;i<n;i++){
          if (nums[i]!=0)prod*=nums[i];
          else ind=i;
      }

      if (cnt==1){
       
        ans[ind]=prod;
        return ans;
      }
      if (cnt>1){
       return ans;
      }
      
      for (int i=0;i<n;i++){
        ans[i]= prod/nums[i];
      }
      return ans;


    }
};
