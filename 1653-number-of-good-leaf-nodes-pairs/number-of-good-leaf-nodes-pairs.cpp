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
        if (root == NULL) {
            vector<int> none;
            none.push_back(0);
            return none;
        }

        vector<int> ret;

        vector<int> left = countDepth(root->left, distance, ans);
        vector<int> right = countDepth(root->right, distance, ans);

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
            if (l > 0) {
                ret.push_back(l + 1);
            }
        }
        for ( auto r : right ) {
            if (r > 0) {
                ret.push_back(r + 1);
            }
        }
        // cout << root->val << endl;
        // for (auto r : ret) {
        //     cout << r << " " ;
        // }
        // cout << endl;

        return ret;

    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        countDepth(root, distance, ans);
        return ans;
    }
};