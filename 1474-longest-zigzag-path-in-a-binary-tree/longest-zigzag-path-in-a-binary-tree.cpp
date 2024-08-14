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
    int max_len = 0;
    int value = 0;
public:
    int findPath(TreeNode* root, int prev ) {
        if (root == NULL) {
            return 0;
        }
        // root->val = value;
        // value++;

        int left = 1 + findPath(root->left, 0);
        int right = 1 + findPath(root->right, 1);
        // cout << root->val << " " << left << " " << right << endl;
        max_len = max(max_len, max(left, right));
        if (prev == 0) {
            return right;
        } else {
            return left;
        }

        return 0;
    }

    int longestZigZag(TreeNode* root) {
        findPath(root, -1);

        return max_len - 1;
    }
};