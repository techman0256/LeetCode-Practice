/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode curr = head;
        ListNode prev =  null;
        
        for (int i=0; i < n && curr != null; i++) {
            curr = curr.next;
        }
        prev = head;

        if (curr == null) {
            return prev.next;
        }
        while (curr.next != null) {
            curr = curr.next;
            prev = prev.next;
        }

        prev.next = prev.next.next;


        return head;
    }
}