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
    int maxDepth(TreeNode *root, bool &ans) {
        if (root == NULL) {
            return 0;
        }

        int left = maxDepth(root->left, ans);
        int right = maxDepth(root->right, ans);

        if ( abs(left - right) > 1 ) ans = false;
        return max(left , right) + 1;
    }
    bool isBalanced(TreeNode* root) {
       bool ans = true;
        maxDepth(root, ans);
       return ans;
    }
};