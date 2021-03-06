/*
	bluepp
	2014-06-12
	2014-07-15
	May the force be with me!
	
	
 	Problem:    Linked List Cycle II
 	Source:     http://oj.leetcode.com/problems/linked-list-cycle-ii/
 	Notes:
 	Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 	Follow up:
 	Can you solve it without using extra space?

 	Solution: From Matthew. Simpler.
*/


    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
        
        ListNode *p1= head, *p2 = head;
        while (p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                break;
        }
        
        if (p1 != p2)
            return NULL;
        
        p2 = head;
        while (p1!= p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
            
        
    }
