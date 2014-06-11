/*
    bluepp
    2014-06-12
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
        if (!head || !head->next)
            return false;
        
        ListNode *p1 = head, *p2 = head;
        while (1)
        {
            if (p1 == NULL || p1->next == NULL || p2 == NULL || p2->next == NULL|| p2->next->next == NULL)
                break;
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                return true;
        }
        
        return false;
        
    }
