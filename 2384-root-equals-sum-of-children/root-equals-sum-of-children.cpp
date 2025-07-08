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
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isLeaf(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        
        return 0;
    }
    
    int checkTree(TreeNode *root)
    {
        if ( isLeaf(root) ) {
            return 1;   
        }
    
        int left = 0, right = 0;
        bool ans = true;
        if (root->left) {
            left = root->left->val;
            ans = ans && checkTree(root->left);
        }
        if (root->right) {
            right = root->right->val;
            ans = ans && checkTree(root->right);
        }
        
        return (int)(ans && (left + right) == root->val);
    }
};