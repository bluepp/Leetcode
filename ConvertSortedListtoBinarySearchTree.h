/*
    bluepp  
    2014-06-06
    May the force be with me!
    
    Problem:    Convert Sorted List to Binary Search Tree
    Source:     https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
    Notes:
    Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

    Solution: Recursion. Pre-order. O(n)
*/

    TreeNode *sortedListToBST(ListNode *head) {
        int n = _getlength(head);
        return _build(head, 0, n-1);
    }
    
    TreeNode* _build(ListNode *& list, int start, int end) 
    {
  
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        
        TreeNode *leftChild = _build(list, start, mid-1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = _build(list, mid+1, end);
        
        return parent;
}
    
    int _getlength(ListNode* head)
    {
        int count = 0;
        ListNode* pCurr = head;
        
        while(pCurr != NULL)
        {
            pCurr = pCurr->next;
            count ++;
        }    
        
        return count;
        
    }
