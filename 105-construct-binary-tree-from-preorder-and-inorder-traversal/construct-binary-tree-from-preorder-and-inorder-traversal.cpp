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
    TreeNode* constructTree(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder, map<int, int> &mpp) {
        // struct TreeNode node = {root, NULL, NULL};

        if ( preStart > preEnd || inStart > inEnd ) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = constructTree(preStart + 1, preStart + numsLeft, inStart, inRoot - 1, preorder, inorder, mpp);
        root->right = constructTree(preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd, preorder, inorder, mpp);

        return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for (int i=0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }


        return constructTree(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder, mpp);
    }
};