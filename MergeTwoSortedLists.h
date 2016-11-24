/*
    bluepp
    
    2014-06-16
    2014-07-16
    2014-08-29
    
    May the force be with me!
    
    Problem:    Merge Two Sorted Lists
    Source:     https://oj.leetcode.com/problems/merge-two-sorted-lists/
    Notes:
    Merge two sorted linked lists and return it as a new list. 
    The new list should be made by splicing together the nodes of the first two lists.

    Solution: ...
 */
 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode dummy(0), *prev = &dummy;
        
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }
            
            prev = prev->next;
        }
        
        if (l1) prev->next = l1;
        if (l2) prev->next = l2;
        
        return dummy.next;
    }
