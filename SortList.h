/*
    bluepp
    
    2014-06-25
    2014-07-26
    2014-08-20
    2014-09-21
    2014-12-05
    
    May the force be with me!
    
   
 Problem:    Sort List
 Source:     http://oj.leetcode.com/problems/sort-list/
 Notes:
 Sort a linked list in O(nlogn) time using constant space complexity.

 Solution: merge sort.
 */
 
 ListNode *sortList(ListNode *head) {
        return _sortList(head, getlength(head));
    }
    
    int getlength(ListNode *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }
    
    ListNode *_sortList(ListNode *&head, int n)
    {
        if (n == 0) return NULL;
        if (n == 1) 
        {
            ListNode* pCurr = head;
            head = head->next;
            pCurr->next = NULL;
            return pCurr;
        }
        
        ListNode* head1 = _sortList(head, n/2);
        ListNode* head2 = _sortList(head, n - n/2);
        return _merge(head1, head2);
    }
    
    ListNode *_merge(ListNode* head1, ListNode* head2)
    { 
        ListNode dummy(0); dummy.next = NULL;
        ListNode *pCurr = &dummy;
        
        while (head1 && head2)
        {

            if (head1->val < head2->val)
            {
                pCurr->next = head1;
                head1 = head1->next;
            }
            else
            {
                pCurr->next = head2;
                head2 = head2->next;
            }
            
            pCurr = pCurr->next;
        }
        
        if (head1) pCurr->next = head1;
        if (head2) pCurr->next = head2;
        
        return dummy.next;
        
    }
