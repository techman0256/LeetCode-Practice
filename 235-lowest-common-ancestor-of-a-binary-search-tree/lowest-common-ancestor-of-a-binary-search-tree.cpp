/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if ( root == NULL ) {
        //     return root;
        // }

        if ( p->val < root->val && q->val < root->val ) {
            // left call only
            return lowestCommonAncestor(root->left, p, q);
        } else if ( p->val > root->val && q->val > root->val ) {
            // right call only
            return lowestCommonAncestor(root->right, p, q);
        } else {
            // both call
            return root;
        }



    }
};