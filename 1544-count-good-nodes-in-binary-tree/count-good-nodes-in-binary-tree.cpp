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
    multiset<int> ms;
    int answer = 0;
    void countNodes(TreeNode* root) {
        if (root == NULL) return;
        ms.insert(root->val);

        if (*ms.rbegin() <= root->val) {
            answer ++;
        }

        countNodes(root->left);
        countNodes(root->right);

        auto curr = ms.find(root->val);
        if (curr != ms.end()) ms.erase(curr);

        return;
    }
    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        countNodes(root);

        return answer;

    }
};