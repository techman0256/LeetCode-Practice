/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

## Approach : 
    - Find the mid-point of the LL
    - Reverse the last part of th LL
    - Reorder 

    1 2 3 4 5 6
    1 2 3 6 5 4

    4 <- 5 6 7
 */


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* mid = findMid(head);
        
        reverseHalf(mid);

        ListNode* p1 = head;
        ListNode* p2 = mid->next;
        mid->next = NULL;

        while (p1 != NULL && p2 != NULL) {
            ListNode* n1 = p1->next; // 2
            ListNode* n2 = p2->next; // null

            p1->next = p2;
            p2->next = n1;
            p1 = n1;
            p2 = n2;
        }

        return;
    }

    void reverseHalf(ListNode* mid) {
        if (mid == NULL || mid->next == NULL ) return;
        ListNode* prev = mid->next;
        ListNode* curr = prev->next;
        prev->next = NULL;

        while (curr != NULL ) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // in the end
        mid->next = prev;
    }

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while ( fast != NULL&& fast->next != NULL  ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};