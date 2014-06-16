/*
    bluepp
    2014-06-16
    May the force be with me!
    
    Problem:    Merge Two Sorted Lists
    Source:     https://oj.leetcode.com/problems/merge-two-sorted-lists/
    Notes:
    Merge two sorted linked lists and return it as a new list. 
    The new list should be made by splicing together the nodes of the first two lists.

    Solution: ...
 */
 
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *l = &dummy;
        
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                l->next = l1;
                l1 = l1->next;
            }
            else
            {
                l->next = l2;
                l2 = l2->next;
            }
            
            l = l->next;
        }
        
        if (l1)
            l->next = l1;
        else
            l->next = l2;
        
        return dummy.next;
       
    }
