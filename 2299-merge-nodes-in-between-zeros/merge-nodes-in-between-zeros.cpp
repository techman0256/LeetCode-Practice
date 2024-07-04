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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while ( curr ) {   
            ListNode* temp = curr;
            while ( curr->next != NULL && curr->val != 0) {
                if (temp != curr) {
                    temp->val += curr->val;
                }
                // cout << temp->val << " " << curr->val << endl;
                

                prev = curr;
                curr = curr->next;
            }
            prev = curr;
            curr = curr->next;
            temp->next = curr;


        }

        return head->next;
    }
};