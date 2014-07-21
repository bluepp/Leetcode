/*
    bluepp
    2014-06-21
    2014-07-21
    May the force be with me!
    
 Problem:    Remove Duplicates from Sorted List
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 Notes:
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.

 Solution: 1. Delete duplicates directly.
           2. Copy value first (like Remove Duplicates from Array) and then delete the remaining elements.
 */
 
 /* my new version */
     ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *pCurr = head;
        while (pCurr)
        {
            ListNode *pNext = pCurr->next;
            if (pNext && pNext->val == pCurr->val) pCurr->next = pNext->next;
            else pCurr = pNext;
        }
        
        return head;
    }
 
 
/* my older version */ 
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode *prev = head, *pCurr = head->next;
        while(pCurr)
        {
            if (prev->val == pCurr->val)
            {
                prev->next= pCurr->next;
                delete(pCurr);
            }
            else
            {
                prev = pCurr;
            }
            pCurr = pCurr->next;
        }
        
        return head;
    }
