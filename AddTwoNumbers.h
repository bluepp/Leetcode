/* 
    Bluepp
    May the force be with me! 
    2014-05-29
    2014-07-06
    2014-08-03
    
    Problem:    Add Two Numbers
    Source:     https://oj.leetcode.com/problems/add-two-numbers/
 
    Notes:
    You are given two linked lists representing two non-negative numbers. 
    The digits are stored in reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8

    Solution: dummy head...

 */
  
  /* seems long, but in fact, maybe faster */
  
   ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) return NULL;
        if (!l1 && l2) return l2;
        if (l1 && !l2) return l1;
        
        ListNode dummy(0);  
      
        int tmp = l1->val + l2->val;
        l1 = l1->next;l2 = l2->next;
        
        int val = tmp%10; int carry = tmp/10;
        ListNode *pnode = new ListNode(val);
        dummy.next = pnode;
        
        while (l1 && l2)
        {
            int tmp = l1->val + l2->val + carry;
            int val = tmp % 10;
            carry = tmp/10;
            
            ListNode *pCurr = new ListNode(val);
            pnode->next = pCurr;
            pnode = pnode->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1)
        {
            int tmp = carry + l1->val;
            int val = tmp % 10;
            carry = tmp/10;
            
            ListNode *pCurr = new ListNode (val);
            pnode->next = pCurr;
            pnode = pnode->next;
            l1 = l1->next;
        }
        
        while (l2)
        {
            int tmp = carry + l2->val;
            int val = tmp%10;
            carry = tmp/10;
            
            ListNode *pCurr = new ListNode (val);
            pnode->next = pCurr;
            pnode = pnode->next;
            l2 = l2->next;
        }
        
        if (carry)
        {
            ListNode *pCurr = new ListNode(1);
            pnode->next = pCurr;
            pnode = pnode->next;
        }
            
        return dummy.next;    
        
    }
    
    
    /* -----2014-08-03------------------ */
       ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       ListNode dummy(0);
       ListNode *pCurr = &dummy;
       int carry = 0;
       
       while (l1 || l2 || carry)
       {
           int sum = carry;
           if (l1)
           {
               sum += l1->val;
               l1 = l1->next;
           }
           if (l2)
           {
               sum += l2->val;
               l2 = l2->next;
           }
           
           carry = sum >= 10 ? 1: 0;
           sum %= 10;
           ListNode *pNode = new ListNode(sum);
           pCurr->next = pNode;
           pCurr = pCurr->next;
           
       }
       
       return dummy.next;
        
    }
