/*
    bluepp
    
    2014-06-18
    2014-07-19
    2014-08-23
    2014-09-17
    
    May the force be with me!
    
    Problem:    Partition List
    Source:     https://oj.leetcode.com/problems/partition-list/
    Notes:
    Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    You should preserve the original relative order of the nodes in each of the two partitions.
    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5.

    Solution: ...
 */
 
     ListNode *partition(ListNode *head, int x) {
        ListNode dummy1(0), dummy2(0);
        ListNode *p1 = &dummy1, *p2 = &dummy2;
        
        ListNode *pCurr = head;
        while (pCurr)
        {
            if (pCurr->val < x)
            {
                p1->next = pCurr;
                p1 = p1->next;
            }
            else
            {
                p2->next = pCurr;
                p2 = p2->next;
            }
            
            pCurr = pCurr->next;
        }
        
        p2->next = NULL;
        p1->next = dummy2.next;
        return dummy1.next;
        
    }
