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
    vector<int> rightSideView(TreeNode* root) {

        map<int, int> nodes;
        vector<int> ans;
        if (root == NULL ) return ans;

        queue<pair<TreeNode*, pair<int, int>>> bfs;
        bfs.push({root, {0, 0}});

        while (!bfs.empty()) {
            TreeNode* top = bfs.front().first;
            int row = bfs.front().second.first;
            int col = bfs.front().second.second;
            bfs.pop();

            nodes[row] = top->val;

            if (top->left) {
                bfs.push({top->left, {row + 1, col - 1}});
            }
            if (top->right) {
                bfs.push({top->right, {row + 1, col + 1}});
            }
        }

        for (auto row : nodes ){
            ans.push_back(row.second);
        }

        return ans;
    }
};