/* 2015-05-12
  bluepp
  May the force be with me!
  
  Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
https://leetcode.com/problems/remove-linked-list-elements/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /* 2015-07-08, update */
 
     ListNode* removeElements(ListNode* head, int val) {
        
        ListNode dummy(0);
        ListNode *prev = &dummy;
        dummy.next = head;
        
        ListNode *pCurr = head;
        while (pCurr)
        {
            if (pCurr->val == val)
            {
                prev->next = pCurr->next;
                delete(pCurr);
                pCurr = prev->next;
            }
            else
            {
                prev = pCurr;
                pCurr = pCurr->next;
            }
        }
        
        return dummy.next;
    }
 
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        ListNode *pCurr = head;
        
        while(pCurr)
        {
            while (pCurr && pCurr->val == val)
            {
                pCurr = pCurr->next;
            }
            
            prev->next = pCurr;
            if (pCurr) 
            {
                prev = pCurr;
                pCurr = pCurr->next;
            }
            
        }
        
        return dummy.next;
    }
};
