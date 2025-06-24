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
        ListNode* carry = new ListNode(0);
        ListNode* ans = new ListNode(-1);
        ListNode* summation = ans;
        while ( l1 != NULL && l2 != NULL ) {
            int sum = l1->val + l2->val + carry->val;
            int unit = sum % 10;
            int carry_digit = (sum - unit) / 10;

            carry->val = carry_digit;
            ListNode* addition = new ListNode(unit);
            ans->next = addition;
            ans = ans->next;
            l1 = l1->next; l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = l1->val + carry->val;
            int unit = sum % 10;
            int carry_digit = (sum - unit) / 10;

            carry->val = carry_digit;
            ListNode* addition = new ListNode(unit);
            ans->next = addition;
            ans = ans->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + carry->val;
            int unit = sum % 10;
            int carry_digit = (sum - unit) / 10;

            carry->val = carry_digit;
            ListNode* addition = new ListNode(unit);
            ans->next = addition;
            ans = ans->next;
            l2 = l2->next;
        }
        if (carry->val > 0) {
            ans->next = carry;
        }
        return summation->next;

    }
};

// follow-up