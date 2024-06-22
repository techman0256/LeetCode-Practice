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
    void traversal(TreeNode* root, int row, map<int, int> &mpp) {
        if (root == NULL) {
            return;
        }

        traversal(root->left, row + 1, mpp);
        traversal(root->right, row + 1, mpp);
        mpp[row] = root->val;

        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if ( root == NULL ) {
            return ans;
        }

        map<int, int> mpp; 
       
        traversal(root, 0, mpp);
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};