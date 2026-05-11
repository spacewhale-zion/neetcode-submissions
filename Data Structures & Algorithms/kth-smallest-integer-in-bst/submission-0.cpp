class Solution {
public:

    int ans;
    int cnt = 0;

    void solve(TreeNode* root, int k) {

        if (!root)
            return;

        solve(root->left, k);

        cnt++;

        if (cnt == k) {
            ans = root->val;
            return;
        }

        solve(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        solve(root, k);

        return ans;
    }
};