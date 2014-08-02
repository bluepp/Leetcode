/*
    bluepp
    2014-06-29
    2014-08-02
    May the force be with me!
    
     
 Problem:    Swap Nodes in Pairs
 Source:     https://oj.leetcode.com/problems/swap-nodes-in-pairs/
 Notes:
 Given a linked list, swap every two adjacent nodes and return its head.
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 Solution: 1. Iterative solution with constant space.
           2. Recursive solution with O(n) space (for practice).
 */


/* iteration solution */
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0);
        ListNode *prev = &dummy, *pCurr = head;
        dummy.next = head;
        
        while (pCurr && pCurr->next)
        {
            ListNode *pNext = pCurr->next;
            ListNode *pNNext = pNext->next;
            
            prev->next = pNext;
            pNext->next = pCurr;
            pCurr->next = pNNext;
            
            prev = pCurr;
            pCurr = pCurr->next;
        }
        
        return dummy.next;
    }
    
/* recursion version */    
     ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *first = head, *second = head->next;
        first->next = second->next;
        second->next = first;
        first->next = swapPairs(first->next);
        
        return second;
    }
