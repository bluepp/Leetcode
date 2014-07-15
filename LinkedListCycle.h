/*
    bluepp
    2014-06-12
    2014-07-15
    May the force be with me!
    
    Problem:    Linked List Cycle
    Source:     http://oj.leetcode.com/problems/linked-list-cycle/
    Notes:
    Given a linked list, determine if it has a cycle in it.
    Follow up:
    Can you solve it without using extra space?

    Solution: two pointers.
*/

     bool hasCycle(ListNode *head) {
        
        if (!head || !head->next) return false;
        
        ListNode *p1 = head, *p2 = head;
        
        while (p1 && p1->next)
        {
            p1 = p1->next->next;
            p2 = p2->next;
            
            if (p1 == p2) return true;
        }
        
        return false;
        
    }
