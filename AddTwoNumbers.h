/* 
    Bluepp
    May the force be with me! 
    2014-05-29
    
    Problem:    Add Two Numbers
    Source:     http://www.leetcode.com/onlinejudge
 
    Notes:
    You are given two linked lists representing two non-negative numbers. 
    The digits are stored in reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8

    Solution: dummy head...

 */
  
   ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
   {
        ListNode dummy(0);
        ListNode *pCurr = &dummy;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = carry;
            
            if (l1)
            {
              sum += l1->value;
              l1 = l1->next;
            }
            if (l2)
            {
              sum += l2->value;
              l2 = l2->value;
            }
            
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            
            ListNode* pNew = new ListNode(sum);
            pCurr->next = pNew;
            pCurr = pCurr->next;
          
            
        }
        
          
        return dummy.next;
        
          
        
   }
