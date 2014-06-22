/*
    bluepp
    2014-06-22
    May the force be with me!
    
  
 Problem:    Reverse Nodes in k-Group
 Source:     https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
 Notes:
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 You may not alter the values in the nodes, only nodes itself may be changed.
 Only constant memory is allowed.
 For example,
 Given this linked list: 1->2->3->4->5
 For k = 2, you should return: 2->1->4->3->5
 For k = 3, you should return: 3->2->1->4->5

 Solution: ...
 */
 
 
 /× TLE, ！！ */
 ListNode *reverseKGroup(ListNode *head, int k) {
        
        ListNode dummy(0), *prev = &dummy, *pCurr = head;
        dummy.next = head;
        
        while(pCurr != NULL)
        {
            prev->next = _reverse(pCurr, k);
            prev = pCurr;
            pCurr = pCurr->next;
        }
        
        return dummy.next;
    }
    
    ListNode* _reverse(ListNode *&phead, int n)
    {
        ListNode *pCurr = phead;
        int length = 0;
        while (pCurr)
        {
            pCurr = pCurr->next;
            length ++;
        }
        
        if (length < n)
            return phead;
        
        ListNode *prev = NULL;
        pCurr = phead;
        for (int i = 0; i < n; i++)
        {
            ListNode *pNext = pCurr;
            pCurr->next = prev;
            prev = pCurr;
            pCurr = pNext;
        }
        
        phead->next = pCurr;
        return prev;;
        
    }
    
