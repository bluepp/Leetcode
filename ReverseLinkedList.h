/*
  2015-07-08
  bluepp
  May the force be with me!
  
  Reverse a singly linked list.
  https://leetcode.com/problems/reverse-linked-list/
*/  

/* iteration */
    ListNode* reverseList(ListNode* head) {
        
        ListNode *pCurr = head, *prev = NULL;
        while (pCurr)
        {
            ListNode *pNext = pCurr->next;
            
            pCurr->next = prev;
            
            prev = pCurr;
            pCurr = pNext;
        }
        
        return prev;
        
    }

/* 2018/10/26 */
    ListNode* reverseList(ListNode* head) {
        
        if (!head || !head->next) return head;
        
        ListNode *p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = NULL;
        
        return head;
    }
    
    
    /* recursion */
       ListNode* reverseList(ListNode* head) {
        
        reverse(head);
        
        return head;
    }
    
    void reverse(ListNode *&head)
    {
        if (!head) return;
        
        ListNode *rest = head->next;
        if (!rest) return;
        
        reverse(rest);
        head->next->next = head;
        head->next = NULL;
        head = rest;
    }
