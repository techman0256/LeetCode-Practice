/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void rec( TreeNode* root, TreeNode* par, vector<TreeNode*> &parent ) {
        if ( root == NULL ) {
            return;
        }

        parent[root->val] = par;

        rec( root->left, root, parent );
        rec( root->right, root, parent );

        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> parent(501);
        vector<int> vis(501, 0);
        vector<int> ans;

        rec( root, NULL, parent);

        queue<pair<TreeNode*, int>> bfs;
        bfs.push({target, 0});
        vis[target->val] = 1;

        while ( !bfs.empty() ) {
            TreeNode* temp = bfs.front().first;
            int dist = bfs.front().second;
            bfs.pop();

            if (dist == k) {
                ans.push_back(temp->val);
            }



            if ( temp->left && vis[temp->left->val] == 0 ) {
                bfs.push({temp->left, dist + 1});
                vis[temp->left->val] = 1;
            }
            if ( temp->right && vis[temp->right->val] == 0 ) {
                bfs.push({temp->right, dist + 1});
                vis[temp->right->val] = 1;
            }
            if ( parent[temp->val] && vis[parent[temp->val]->val] == 0 ) {
                bfs.push({parent[temp->val], dist + 1});
                vis[parent[temp->val]->val] = 1;
            }
        }

        return ans;

    }
};