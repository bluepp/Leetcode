/*
2016-08-30
bluepp
May the force be with me!

https://leetcode.com/problems/linked-list-random-node/

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
*/

class Solution {
private:
    int len;
    ListNode *head;
    
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        
        len = 0;
        this->head = head;
        
        ListNode *pCurr = head;
        while (pCurr)
        {
            len++;
            pCurr = pCurr->next;
        }
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        
        int t = rand() % len;
        
        ListNode *pCurr = head;
        while (t)
        {
            pCurr = pCurr->next;
            t--;
        }
        
        return pCurr->val;
    }
};

