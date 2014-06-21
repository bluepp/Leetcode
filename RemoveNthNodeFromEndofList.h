/*
    bluepp
    2014-06-21
    May the force be with me!
    
    
 Problem:    Remove Nth Node From End of List
 Source:     https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
 Notes:
 Given a linked list, remove the nth node from the end of list and return its head.
 For example,
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 Solution: head---back------front------>NULL
                   |          |
                   ---> n <----
 */
 
    ListNode *removeNthFromEnd(ListNode *head, int n) {
       ListNode dummy(0), *back = &dummy, *front = &dummy;
        dummy.next = head;
        while (n--) front = front->next;
        while (front->next) {
            front = front->next;
            back = back->next;
        }
        ListNode *del = back->next;
        back->next = del->next;
        delete del;
        return dummy.next;
    }
