class Solution {
public:
    int solve(int ind,int p,vector<int>& nums,int n){

        if (ind>=n)return 1;
        int pick=1,notPick=1;

        pick=solve(ind+1,p*nums[ind],nums,n);
        notPick=solve(ind+1,1,nums,n);
        return max(pick,notPick);
    }
    int maxProduct(vector<int>& nums) {
    
    int min_ = nums[0];
    int max_ = nums[0];

    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {

        if (nums[i] < 0)
            swap(min_, max_);

        min_ = min(nums[i], nums[i] * min_);

        max_ = max(nums[i], nums[i] * max_);

        ans = max(ans, max_);
    }

    return ans;
}
};
