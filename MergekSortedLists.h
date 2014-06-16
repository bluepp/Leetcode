/*
    bluepp
    2014-06-16
    May the force be with me!
    
    Problem:    Merge k Sorted Lists
    Source:     https://oj.leetcode.com/problems/merge-k-sorted-lists/
    Notes:
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
    Solution: Find the smallest list-head first using minimum-heap(lgk).
               complexity: O(NlgK)
 */
 
class Mycompare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

 
 
class Solution {
   
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<listNode*>&lists, Mycompare q>;
        
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
                q.push(lists[i]);
        }
        
        ListNode dummy(0), *p = &dummy;
        while (!q.empty())
        {
            ListNode *pCurr = q.top();
            q.pop();
            p->next = pCurr;
            p = p->next;
            
            if (pCurr->next)
                pCurr = pCurr->next;
        }
        
        return dummy.next;
    }
};
