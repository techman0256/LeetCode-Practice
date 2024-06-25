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
    void recover(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second, TreeNode* &middle) {
        if (root == NULL) return;

        recover(root->left, prev, first, second, middle);

        if ( prev != NULL && (root->val < prev->val) ) {
            if ( first == NULL ) {
                first = prev;
                middle = root;
            } else {
                second = root;
            }
        }

        prev = root;
        
        recover(root->right, prev, first, second, middle);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* second = NULL;
        recover(root, prev, first, second, middle);

        if (first && second) {
            // cout << first->val << " " << second->val << endl;
            swap(first->val, second->val);
        }
        else if (first && middle) {
            // cout << first->val << " " << middle->val << endl;
            swap(first->val, middle->val);
        }
        // return root;
        
    }
};