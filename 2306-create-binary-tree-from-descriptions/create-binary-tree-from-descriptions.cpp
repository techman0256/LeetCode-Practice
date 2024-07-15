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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        map<int, TreeNode*> nodes;
        set<int> childrens;

        for (int i=0; i < n; i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            cout << parent << " " << child << " " << isLeft << endl;
            if ( nodes.find(parent) == nodes.end() ) {
                nodes[parent] = new TreeNode(parent);
            }
            TreeNode* ch;
            if ( nodes.find(child) == nodes.end() ) {
                ch = new TreeNode(child);
                nodes[child] = ch;
            }
            childrens.insert(child);

            if (isLeft == 1) {
                nodes[parent]->left = nodes[child];
                // cout << nodes[parent]->val  << " " << nodes[parent]->left->val << endl;
            } else {
                nodes[parent]->right = nodes[child];
                // cout << nodes[parent]->right->val << endl;
            }
        }

        for ( auto node : nodes ) {
            if (childrens.find(node.first) == childrens.end()) {
                cout << node.second->val;
                return node.second;
            }
        }

        return NULL;

    }
};