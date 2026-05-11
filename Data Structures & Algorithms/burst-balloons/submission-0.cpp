class Solution {
public:
    map<vector<int>,int>mp;
    int solve(vector<int>&nums){

        int n=nums.size();
        if (n==2)return 0;
        if (mp.find(nums)!=mp.end())return mp[nums];
        int ans=0;
        for (int i=1;i<n-1;i++){
            int coins=nums[i]*nums[i+1]*nums[i-1];
            int temp=nums[i];
            nums.erase(nums.begin()+i);
            ans=max(ans,+coins+solve(nums));
            nums.insert(nums.begin()+i,temp);
        }
        mp[nums]=ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        return solve(nums);
    }
};
