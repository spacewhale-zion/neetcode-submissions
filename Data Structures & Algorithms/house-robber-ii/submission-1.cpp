class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1)return nums[0];
        vector<int>dp1(n+2,0);

        for (int i=n-2;i>=0;i--){
            int pick=dp1[i+2]+nums[i];
            int notPick=dp1[i+1];
            dp1[i]=max(pick,notPick);
        }

        vector<int>dp2(n+2,0);

        for (int i=n-1;i>=1;i--){
            int pick=dp2[i+2]+nums[i];
            int notPick=dp2[i+1];
            dp2[i]=max(pick,notPick);
        }

        return max(dp1[0],dp2[1]);


        
    }
};
