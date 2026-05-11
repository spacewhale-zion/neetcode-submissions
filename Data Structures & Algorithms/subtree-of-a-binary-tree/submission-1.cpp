/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSame(TreeNode*root,TreeNode*sub){
        if (!root && !sub)return true;
        else if (!root) return false;
        else if (!sub)return false;
        return isSame(root->left,sub->left) && isSame(root->right,sub->right) && root->val == sub->val;
    }
    bool solve(TreeNode*root,TreeNode*sub){
        if (!root)return false;
        bool pick=false;
        if (root->val == sub->val)pick= isSame(root,sub);
        return solve(root->left,sub) || solve(root->right,sub) || pick;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root,subRoot);
    }
};
