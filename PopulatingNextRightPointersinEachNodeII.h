/*
    bluepp
    2014-06-19
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
 
 
 /* TLE */
 
    void connect(TreeLinkNode *root) {
            
            while (root)
            {
                TreeLinkNode *pLevel = root;
                TreeLinkNode *pNext = pLevel->next;
                while (pNext && !pNext->left && !pNext->right)
                    pNext = pNext->next;
                
               
                while (pLevel)
                {
                    if (pLevel->left)
                    {
                        if (pLevel->right)
                        {
                            pLevel->left->next = pLevel->right;
                        }
                        else
                        {
                            pLevel->left->next = pNext ? (pNext->left ? pNext->left : pNext->right): NULL;
                           
                        }
                            
                    }
                    
                    if (pLevel->right)
                    {
                        pLevel->right->next = pNext ? (pNext->left ? pNext->left : pNext->right) : NULL;
                       
                    }
                    
                    pLevel = pNext;
               
                } // while
                
                
                
                root = root->left ? root->left : root->right;
            }
         
            
      
        
    }
