/*
    bluepp
    2014-06-07
    May the force be with me!
    
    Problem:    Copy List with Random Pointer
    Source:     http://oj.leetcode.com/problems/copy-list-with-random-pointer/
    Notes:
    A linked list is given such that each node contains an additional random pointer 
    which could point to any node in the list or null.
    Return a deep copy of the list.

    Solution: Solution 1 uses constant extra space.
*/

/* Solution 1 */

RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode *pCurr = head;
        while (pCurr)
        {
            RandomListNode *pNew = new RandomListNode(pCurr->label);
            pNew->next = pCurr->next;
            pCurr->next = pNew;
            pCurr = pCurr->next->next;
        }
        
        pCurr = head;
        while (pCurr)
        {
            if (pCurr->random)
            {
                pCurr->next->random = pCurr->random->next;
            }
            pCurr = pCurr->next->next;
        }
        
         RandomListNode dummy(0), *pCurrNew = &dummy;

        pCurr = head;
        
        while (pCurr)
        {
            pCurrNew->next = pCurr->next;
            pCurrNew = pCurrNew->next;
            pCurr->next = pCurr->next->next;
            pCurr = pCurr->next;
            
        }
  
        return dummy.next;
        
    }





/* Solution 2 */
    RandomListNode *copyRandomList(RandomListNode *head) {  
        if (!head)
            return NULL;
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode dummy(0), *pCurrNew = &dummy, *pCurr = head;
        
        while (pCurr)
        {
            if (map.find(pCurr) == map.end())
            {
                map[pCurr] = new RandomListNode(pCurr->label);
            }
            if (pCurr->random && map.find(pCurr->random) == map.end())
            {
                map[pCurr->random] = new RandomListNode(pCurr->random->label);
            }
            
            pCurrNew->next = map[pCurr];
            pCurrNew = pCurrNew->next;
            pCurrNew->random = map[pCurr->random];
            pCurr = pCurr->next;
        }
        
        return dummy.next;
        
    }
    
    
