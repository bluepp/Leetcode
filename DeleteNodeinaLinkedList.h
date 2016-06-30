/*
  2015-07-20
  bluepp
  May the force be with me!
  
Write a function to delete a node (except the tail) in a singly linked list,
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,
the linked list should become 1 -> 2 -> 4 after calling your function.

https://leetcode.com/problems/delete-node-in-a-linked-list/
*/


/* 2016-07-01 */
    void deleteNode(ListNode* node) {
        
        ListNode *pNext = node->next;
        
        node->val = pNext->val;
        node->next = pNext->next;
        
        delete pNext;
    }


    void deleteNode(ListNode* node) {
        if (!node) return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
