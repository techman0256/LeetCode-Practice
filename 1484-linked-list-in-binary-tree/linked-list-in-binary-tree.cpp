/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool downPath(ListNode *head, TreeNode *root) {
        if (head == NULL && root == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (head == NULL) return true;
        if (head->val != root->val) return false;

        return downPath(head->next, root->left) || downPath(head->next, root->right);


    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL && root == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (head == NULL) return true;
        

        bool left1 = false, right1 = false, left2 = false, right2 = false;
        if (head->val == root->val && downPath(head, root)) {
            // left1 = isSubPath(head->next, root->left);
            // right1 = isSubPath(head->next, root->right);
            return true;
        }


        return left1 || right1 || isSubPath(head, root->left) || isSubPath(head, root->right);

    }

};