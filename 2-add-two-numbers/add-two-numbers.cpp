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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tempHead = new ListNode(-1);
        ListNode* curr = tempHead;
        int carry = 0;
        while ( l1 != NULL || l2 != NULL || carry != 0 ) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            int unit = sum % 10;

            curr->next = new ListNode(unit);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr; 
            l2 = l2 ? l2->next : nullptr;
        }
        
        return tempHead->next;

    }
};

// follow-up 
// What if the Number is not given in reverse order ?