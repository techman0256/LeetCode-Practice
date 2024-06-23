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
    int widthOfBinaryTree(TreeNode* root) {
        if ( !root ) return 0;
        queue<pair<TreeNode*, long long>> bfs;
         
        int ans = 0;
        
        bfs.push({root, 0});
        while ( !bfs.empty() ) {
            int size = bfs.size();
            long long mmin = bfs.front().second;

            long long first, last;

            for (int i=0; i < size; i++) {
                long long curr_id = bfs.front().second - mmin;
                TreeNode *node = bfs.front().first;
                bfs.pop();

                if (i == 0) first = curr_id;
                if (i == size - 1) last = curr_id;

                if (node->left) bfs.push({node->left, curr_id * 2 + 1});
                if (node->right) bfs.push({node->right, curr_id * 2 + 2});


            }
            
            ans = max(ans, (int)last - (int)first + 1);

        }

        

        return ans;
    }
};