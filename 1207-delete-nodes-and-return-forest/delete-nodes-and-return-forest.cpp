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
    TreeNode* traverse(TreeNode* root, set<int>& del, vector<TreeNode*> &forest) {
        if (root == NULL) {
            return NULL;
        }

        if ( del.find(root->val) != del.end() ) {
            if (root->left) {
                if (del.find(root->left->val) == del.end()) {
                    forest.push_back(root->left);
                }
                TreeNode* left = traverse(root->left, del, forest);
            }
            if (root->right) {
                if (del.find(root->right->val) == del.end()) {
                    forest.push_back(root->right);
                }
                TreeNode* right = traverse(root->right, del, forest);
            }

            return NULL;
        }

        root->left = traverse(root->left, del, forest);
        root->right = traverse(root->right, del, forest);

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int n = to_delete.size();
        set<int> del;
        for (int i=0; i < n; i++) {
            del.insert(to_delete[i]);
        }

        vector<TreeNode*> forest;
        if (del.find(root->val) == del.end()) {
            forest.push_back(root);

        }
        traverse(root, del, forest);
        return forest;
        
    }
};