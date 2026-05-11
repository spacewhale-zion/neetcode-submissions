class Solution {
public:

    vector<vector<int>> ans;

    void solve(vector<int>& nums, int idx) {

        // permutation completed
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            // choose
            swap(nums[idx], nums[i]);

            // explore
            solve(nums, idx + 1);

            // backtrack
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        solve(nums, 0);

        return ans;
    }
};