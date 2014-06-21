/*
    bluepp
    2014-06-21
    May the force be with me!
    
 Problem:    Reorder List
 Source:     http://oj.leetcode.com/problems/reorder-list/
 Notes:
 Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 You must do this in-place without altering the nodes' values.
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

 Solution: Reverse the back half first, then reorder.
*/


void reorderList(ListNode *head) {
        if (!head || !head->next)
            return;
        
        ListNode *p1 = head, *p2 = head, *prev = NULL;
        while(p2 && p2->next)
        {
            prev = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        prev->next = NULL;
        
        ListNode *pCurr = p1, *pNext = pCurr->next;
        while(pNext)
        {
            ListNode *pNNext = pNext->next;
            pNext->next = pCurr;
            pCurr = pNext;
            pNext = pNNext;
        }
        
        ListNode *pTailHead = pCurr;
        p1->next = NULL;
        
        ListNode *p1Curr = head;
        ListNode *p2Curr = pTailHead;
        while (p1Curr && p2Curr)
        {
            ListNode *p1Next = p1Curr->next;
            ListNode *p2Next = p2Curr->next;
            
            p1Curr->next = p2Curr;
            if (p1Next)
            {
                p2Curr->next = p1Next;
            }
            p1Curr = p1Next;
            p2Curr = p2Next;
            
        }
     
    }
