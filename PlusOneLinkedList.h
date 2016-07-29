/*
2016-07-29
bluepp
May the force be with me!

https://leetcode.com/problems/plus-one-linked-list/

Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
*/

    ListNode* plusOne(ListNode* head) {
        
        ListNode *new_head = _reverse(head);
        
        int carry = 1;
        ListNode *pCurr = new_head, *prev = NULL;
        while (pCurr)
        {
            int t = pCurr->val + carry;
            
            pCurr->val = t % 10;
            carry = t /10;
            
            prev = pCurr;
            pCurr = pCurr->next;
        }
        
        if (carry)
        {
            prev->next = new ListNode(1);
        }
        
        ListNode *ret_head = _reverse(new_head);
        return ret_head;
    }
    
    
    ListNode *_reverse(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode *pCurr = head, *prev = NULL;
        
        while (pCurr)
        {
            ListNode *pNext = pCurr->next;
            
            pCurr->next = prev;
            prev = pCurr;
            pCurr = pNext;
        }
        
        return prev;
    }
