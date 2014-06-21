/*
    bluepp
    2014-06-21
    May the force be with me!
    
    
 Problem:    Reverse Linked List II
 Source:     https://oj.leetcode.com/problems/reverse-linked-list-ii/
 Notes:
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 return 1->4->3->2->5->NULL.
 Note:
 Given m, n satisfy the following condition:
 1 <= m <= n <= length of list.

 Solution: in-place & one-pass.
 */
    
    
 ListNode *reverseBetween(ListNode *head, int m, int n) {
  
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        
        for (int i = 0; i < m-1; i++)
        {
            prev = prev->next;
        }
        
        ListNode *pCurr = prev ->next;
        ListNode *pEnd = pCurr;
        ListNode *pprev = NULL;
        
        for(int i = 0; i <= n-m; i++)
        {
            ListNode *pNext = pCurr->next;
            pCurr->next = pprev;
            pprev = pCurr;
            pCurr = pNext;
            
        }
        
        prev->next = pprev;
        pEnd->next = pCurr;
        
        return dummy.next;
        
    }
