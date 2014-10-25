/*
    bluepp
    
    2014-06-19
    2014-07-20
    2014-09-02
    2014-09-19
    2014-10-24
    
    May the force be with me!
  
 lating Next Right Pointers in Each Node II
 Source:     https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 Notes:
 Follow up for problem "Populating Next Right Pointers in Each Node".
 What if the given tree could be any binary tree? Would your previous solution still work?
 Note:
 You may only use constant extra space.
 For example,
 Given the following binary tree,
     1
    /  \
   2    3
  / \    \
 4   5    7
 After calling your function, the tree should look like:
     1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \    \
 4-> 5 -> 7 -> NULL

 Solution: 1. iterative way with CONSTANT extra space.
           2. iterative way + queue. Contributed by SUN Mian(孙冕).
           3. tail recursive solution.
 */
 

/* my version */
    void connect(TreeLinkNode *root) {
        
        TreeLinkNode *pCurr = root;
        
        while (pCurr)
        {
            TreeLinkNode *pNode = pCurr;
            TreeLinkNode *pNext = NULL, *pLast = NULL;
            
            while (pNode)
            {
               TreeLinkNode *pLeft = pNode->left, *pRight = pNode->right;
               
               if (pLeft || pRight)
               {
                   if (pLast) pLast->next = pLeft ? pLeft : pRight;
                   if (pLeft) pLeft->next = pRight;
                   if (!pNext) pNext = pLeft ? pLeft : pRight;
                   pLast = pRight ? pRight : pLeft;
               }
               
               pNode = pNode->next;
            }
            
            pCurr = pNext;
        }
    }






 
    void connect(TreeLinkNode *root) {
        TreeLinkNode *pCurr = root;
        
        while (pCurr)
        {
            TreeLinkNode *pNode = pCurr, *pLast = NULL;
            pCurr = NULL;
            
            while (pNode)
            {
                TreeLinkNode *left = pNode->left, *right = pNode->right;
                
                if (left || right)
                {
                    if (pLast) pLast->next = left ? left:right;
                    if (left) left->next = right;
                    if (!pCurr) pCurr = left ? left : right;
                    pLast = right ? right : left;
                }
                
                pNode = pNode->next;
            }
        }
    }
    
    ----------------------
