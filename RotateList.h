/*
    bluepp
    2014-06-22
    2014-07-23
    May the force be with me!
    
    
 Problem:    Rotate List
 Source:     https://oj.leetcode.com/problems/rotate-list/
 Notes:
 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.

 Solution: Notice that k can be larger than the list size (k % list_size).
           This solution traverses the list twice at most.
*/

    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        
        ListNode* tail = head;
        int count = 1;
        while (tail->next)
        {
            tail = tail->next;
            count++;
        }
        k = k % count;   // in case the list rotates more than one round.
        if (k == 0) return head;
        
        ListNode* cur = head;
        for (int i = 0; i < count - k - 1; i++)
            cur = cur->next;
        
        ListNode* newHead = cur->next;
        cur->next = NULL;
        tail->next = head;
        
        return newHead;
    }
