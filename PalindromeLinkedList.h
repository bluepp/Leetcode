/*
  2015-07-15
  bluepp
  May the force be with me!
  
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
https://leetcode.com/problems/palindrome-linked-list/

*/

    bool isPalindrome(ListNode* head) {
        ListNode *p1 = head, *p2 = head;
        
        while (p1 && p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode * head2 = reverse(p1);
        
        while (head && head2)
        {
            if (head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
    
    ListNode *reverse(ListNode *head)
    {
        if (!head) return head;
        
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
