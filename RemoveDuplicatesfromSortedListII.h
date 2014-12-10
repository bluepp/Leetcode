/*
    bluepp
    
    2014-06-21
    2014-07-22
    2014-12-03
    2014-12-10
    
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

/* 2014-12-10 */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        
        ListNode *pCurr = head;
        
        while (pCurr)
        {
            ListNode *pNext = pCurr->next;
            
            bool bDel = false;
            while (pNext && pNext->val == pCurr->val)
            {
                bDel = true;
                
                ListNode *pDelete = pNext;
                pNext = pNext->next;
                delete(pDelete);
            }
            
            if (bDel)
            {
                delete(pCurr);
                prev->next = pNext;
            }
            else
            {
                prev = pCurr;
            }
            
            pCurr = pNext;
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
    
