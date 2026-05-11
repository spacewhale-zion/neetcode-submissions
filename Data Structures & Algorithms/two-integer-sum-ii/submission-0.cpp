class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;

        while (i<j){
          if (nums[i]==nums[j]){
            i+=1;
            continue;
          }
          int sum=nums[i]+nums[j];
          if (sum-target==0){
            return {i+1,j+1};
          }
          if (sum-target>0){
            j-=1;
          }
          if (sum-target<0){
            i+=1;
          }
        }
        return {-1,-1};
    }
};
