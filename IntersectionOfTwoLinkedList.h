/*
  2014-12-07
  bluepp
  May the force be with me!
  
  https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
  
  Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

*/

/* my solution */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *p1 = headA, *p2 = headB;
        if (!p1 || !p2) return NULL;
        
        int n1 = len(p1), n2 = len(p2);
        int d = 0;
        bool p1first = false;
        if (n1 > n2)
        {
            d = n1-n2;
            p1first = true;
        }
        else
        {
            d = n2-n1;
        }
        
        if (p1first)
        {
            while (d > 0)
            {
                p1 = p1->next;
                d--;
            }
        }
        else
        {
            while (d > 0)
            {
                p2 = p2->next;
                d--;
            }
        }
        
        
        while (p1 && p2)
        {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return NULL;
        
    }
    
    int len(ListNode *head)
    {
        ListNode *p = head;
        int count = 0;
        
        while (p)
        {
            count ++;
            p = p->next;
        }
        
        return count;
    }


