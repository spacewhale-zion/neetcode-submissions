class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>&nums,int target,vector<int>&temp,int ind){
        if (ind>=nums.size()){
        if(target==0)ans.push_back(temp);
        return ;
        }


        if (target-nums[ind]>=0){
            temp.push_back(nums[ind]);
            solve(nums,target-nums[ind],temp,ind);
            temp.pop_back();
        }
        solve(nums,target,temp,ind+1);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        solve(nums,target,temp,0);
        return ans;
    }
};
