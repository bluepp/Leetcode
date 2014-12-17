/*
    bluepp
    
    2014-06-16
    2014-07-16
    2014-09-02
    2014-09-07
    2014-10-16
    2014-11-16
    
    May the force be with me!
    
    Problem:    Merge k Sorted Lists
    Source:     https://oj.leetcode.com/problems/merge-k-sorted-lists/
    Notes:
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
    Solution: Find the smallest list-head first using minimum-heap(lgk).
               complexity: O(NlgK)
 */
 
/* recursion */

 
 
/* traditional ways */
class Mycompare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
   
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, Mycompare> q;
        
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
                q.push(pCurr->next);
        }
        
        return dummy.next;
    }
};



/* recursion, TLE, 2014-12-17 */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        
        vector<ListNode *>::iterator it = lists.begin();
        return merge(it, n);
    }
    
    ListNode *merge(vector<ListNode *>::iterator it, int n)
    {
        if (n == 0) return NULL;
        if (n == 1) return *it;
        if (n == 2) return merge2(*it, *(it+1));
        
        merge(it, n/2);
        merge(it, n-n/2);
    }
    
   
    ListNode *merge2(ListNode *p1, ListNode *p2)
    {
        ListNode dummy(0), *prev = &dummy;
        
        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                prev->next = p1;
                prev = p1;
                p1 = p1->next;
            }
            else
            {
                prev->next = p2;
                prev = p2;
                p2 = p2->next;
            }
        }
        
        if (p1) prev->next = p1;
        if (p2) prev->next = p2;
        
        return dummy.next;
    }
