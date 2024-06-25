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
    bool find(TreeNode* root, int k, set<int> &mpp) {
        if (root == NULL) {
            return false;
        }

        if ( mpp.find(k - root->val) != mpp.end() ) {
            return true;
        } else {
            mpp.insert(root->val);
        }

        bool left = find(root->left, k, mpp);
        bool right = find(root->right, k, mpp);
        // if (root->val == ) {
        // }
        cout << root->val << " " << left << " " << right << endl;

        return left || right;
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> mpp;
        return find(root, k, mpp);
    }
};