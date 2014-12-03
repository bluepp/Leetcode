/*
    bluepp
    
    2014-06-21
    2014-07-22
    2014-12-03
    
    May the force be with me!
    
 Problem:    Remove Duplicates from Sorted List II
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

 Solution: 1. iterative 2. recursive
 */

    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *pCurr = prev->next;
        
        while (pCurr)
        {
            bool del = false;
            while (pCurr && pCurr->next && pCurr->val == pCurr->next->val)
            {
                del = true;
                ListNode *pDel = pCurr;
                pCurr = pCurr->next;
                delete(pDel);
            }
            
            if (del)
            {
                ListNode *pDel = pCurr;
                prev->next = pCurr->next;
                delete(pDel);
            }
            else
            {
                prev = pCurr;
            }
            
            pCurr = pCurr->next;
            
        }
        
        return dummy.next;
        
    }
    
--------------------------------

    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        if (head->next && head->next->val != head->val)
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        
        int val = head->val;
        while (head && head->val == val)
        {
            ListNode *pDel = head;
            head = head->next;
            delete(pDel);
        }
        
        return deleteDuplicates(head);
       
        
    }
    
