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
    vector<int> countDepth(TreeNode* root, int distance, int &ans) {
        vector<int> ret, left, right;

        if (root->left) {
            left = countDepth(root->left, distance, ans);
        }
        if (root->right) {
            right = countDepth(root->right, distance, ans);
        }

        for ( auto l : left ) {
            for (auto r : right) {
                if (l > 0 && r > 0 && l + r <= distance) {
                    ans ++;
                }
            }
        }

        if (root->left == NULL && root->right == NULL) {
            ret.push_back(1);
        }

        for ( auto l : left ) {
            if (l > 0 && l < distance) {
                ret.push_back(l + 1);
            }
        }
        for ( auto r : right ) {
            if (r > 0 && r < distance) {
                ret.push_back(r + 1);   
            }
        }

        return ret;

    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        countDepth(root, distance, ans);
        return ans;
    }
};