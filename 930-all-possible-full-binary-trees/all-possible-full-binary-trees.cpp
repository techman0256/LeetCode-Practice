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
    vector<TreeNode*> allPossibleFBT(int n) {
        // base case
        if (n == 1) {
            vector<TreeNode*> ans;
            TreeNode* node = new TreeNode(0);
            ans.push_back(node);

            return ans;
        }

        int even = n - 1;
        vector<TreeNode*> left, right;
        vector<TreeNode*> ret;
        TreeNode* root;
        for (int i=1; i < even; i+= 2) {
            // cout << i << " " << even - i << endl;
            left = allPossibleFBT(i);
            right = allPossibleFBT(even - i);
            
            for ( auto l : left ) {
                for ( auto r : right ) {
                    root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ret.push_back(root);

                }
            }
        }


        return ret;
    }
};