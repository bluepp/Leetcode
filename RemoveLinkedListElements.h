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
