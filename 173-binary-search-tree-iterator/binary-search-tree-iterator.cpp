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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode* iter;

    BSTIterator(TreeNode* root) {
        iter = root;
        while (iter != NULL) {
            stk.push(iter);
            iter = iter->left;
        }
    }
    
    int next() {
        if (stk.size() == 0) {
            return -1;
        }

        iter = stk.top();
        stk.pop();
    
        // if (iter == NULL) {
        TreeNode* temp = iter->right;
        while (temp != NULL) {
            stk.push(temp);
            temp = temp->left;
        }

        return iter->val; 
    }
    
    bool hasNext() {
        if (stk.size() == 0) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */