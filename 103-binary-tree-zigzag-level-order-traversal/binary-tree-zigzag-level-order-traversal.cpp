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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> bfs;
        bfs.push(root);
        // ans.push_back(vector<int> (1, root->val));

        int alt = 0;

        while ( !bfs.empty() ) {
            int n = bfs.size();
            vector<int> level;

            for (int i=0; i < n; i++) {
                TreeNode *curr = bfs.front();
                bfs.pop();
                
                level.push_back(curr->val);
                if (curr->left != NULL) bfs.push(curr->left);
                if (curr->right != NULL) bfs.push(curr->right);                
            }

            if (alt == 0) alt = 1;
            else {
                reverse(level.begin(), level.end());
                alt = 0;
            }
            ans.push_back(level);

        }
        return ans;
    }
};