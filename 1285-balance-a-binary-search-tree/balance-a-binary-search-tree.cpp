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
    void balance(TreeNode* root, vector<int> &inorder) {
        if (root == NULL) {
            return;
        }

        balance(root->left, inorder);
        inorder.push_back(root->val);
        balance(root->right, inorder);

        return;
    }
    TreeNode* insert(vector<int> &inorder, int left, int right) {
        if ( left > right  ) {
            return NULL;
        }
        int mid = (left + right )/2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = insert(inorder, left, mid - 1);
        root->right = insert(inorder, mid + 1, right);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        balance(root, inorder);
        return insert(inorder, 0, inorder.size() - 1);

        // return root;





    }
};