/*
    bluepp
    2014-06-16
    2014-07-16
    May the force be with me!
    
    Problem:    Merge Two Sorted Lists
    Source:     https://oj.leetcode.com/problems/merge-two-sorted-lists/
    Notes:
    Merge two sorted linked lists and return it as a new list. 
    The new list should be made by splicing together the nodes of the first two lists.

    Solution: ...
 */
 
   ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
       ListNode dummy(0);
       ListNode*pCurr = &dummy;
       ListNode *p1 = l1, *p2 = l2;
       
       while (p1 && p2)
       {
           int value = 0;
           if (p1->val < p2->val)
           {
               pCurr->next = p1;
               p1 = p1->next;
           }
           else 
           {
               pCurr->next = p2;
               p2 = p2->next;
           }
           
           pCurr = pCurr->next;
       }
       
       if (p1) pCurr->next = p1;
       if (p2) pCurr->next = p2;
       
       return dummy.next;
        
       
    }
