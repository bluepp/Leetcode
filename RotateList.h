/*
    bluepp
    2014-06-22
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

/** ??????, wrong !!! */
ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next)
            return head;
            
        ListNode dummy(0);
        ListNode *p1 = &dummy, *p2 = &dummy;
        dummy.next = head;
        
        for (int i = 0; i < k; i++)
        {
            if (p2)
                p2 = p2->next;
            else
                return dummy.next;
        }
        
        while (p2->next)
        {
            if (p1 && p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                return dummy.next;
            }
        }
        
        ListNode *pp2 = p1->next, *prev = NULL;
        while (pp2)
        {
            ListNode *pNext = pp2->next;
            pp2->next = prev;
            prev = pp2;
            pp2 = pNext;
        }
        
        p1->next = prev;
        
        return dummy.next;
        
    }
