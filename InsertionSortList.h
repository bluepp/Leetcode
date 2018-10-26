/*
  2014-09-09
  2014-09-14
  2014-09-16
  
  bluepp
  May the force be with me!
  
 Source:     http://oj.leetcode.com/problems/insertion-sort-list/
 Notes:
 Sort a linked list using insertion sort.

 Solution: ...
 */

/* 2018/10/26  */

    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        ListNode *pCurr = &dummy;
        
        while (head) {
            ListNode *pNext = head->next;
            
            pCurr = &dummy;
            
            while (pCurr->next && pCurr->next->val <= head->val) {
                pCurr = pCurr->next;
            }
            
            head->next = pCurr->next;
            pCurr->next = head;
            head = pNext;
        }
        
        return dummy.next;
    }


 
     ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *pCurr = &dummy;
        
        while (pCurr->next)
        {
            if (pCurr->next->val >= pCurr->val)
            {
                pCurr = pCurr->next;
            }
            else
            {
                insert(&dummy, pCurr, pCurr->next);
            }
            
        }
        
        return dummy.next;
    }
    
    void insert(ListNode *head, ListNode *tail, ListNode *pNode)
    {
        ListNode *pCurr = head;
        
        while (pCurr->next->val < pNode->val)
            pCurr = pCurr->next;
        
        tail->next = pNode->next;
        pNode->next = pCurr->next;
        pCurr->next = pNode;
    }
  
