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
struct Node{
    int row;
    int col;
    int val;
};

class Solution {
public:
    void giveOrder(int row, int col, TreeNode *root, vector<struct Node> &order) {
        if (root == NULL) {
            return;
        }
        struct Node curr = {row, col, root->val};

        order.push_back(curr);
        giveOrder(row + 1, col - 1, root->left, order);
        giveOrder(row + 1, col + 1, root->right, order);

        return;
    }
    static bool compare(struct Node x, struct Node y) {
        if (x.row == y.row && x.col == y.col) {
            return x.val < y.val;
        }
        if (x.col == y.col) {
            return x.row < y.row;
        }
        return x.col < y.col;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<struct Node> order;
        vector<vector<int>> ans;
        giveOrder(0, 0, root, order);

        sort(order.begin(), order.end(), compare);
        vector<int> col;
        int prev_col = INT_MIN;
        for ( auto node : order) {
            if (prev_col != node.col) {
                prev_col = node.col;
                ans.push_back(col);
                col.clear();
            }
            col.push_back(node.val);
        }
        ans.push_back(col);
        ans.erase(ans.begin());
        
        return ans;
    }
};