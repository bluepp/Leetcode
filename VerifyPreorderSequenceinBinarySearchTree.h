/*  
  2015-08-14
  bluepp
  May the force be with me!
  
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/

*/


/* 1. stack, 2.constant space , 3. divide and conquer, set lower and upper bound*/

/* 2017-01-10, update, stack */

    bool verifyPreorder(vector<int>& preorder) {
        
        int low = INT_MIN;
        stack<int> s;
        
        for (auto p : preorder)
        {
            if (p < low) return false;
            
            while (!s.empty() && p > s.top())
            {
                low = s.top();
                s.pop();
            }
            
            s.push(p);
        }
        
        return true;
    }



/* stack , https://leetcode.com/discuss/51543/java-o-n-and-o-1-extra-space */

    bool verifyPreorder(vector<int>& preorder) {
        
        int low = INT_MIN;
        stack<int> s;
        
        int n = preorder.size();
        if (n == 0) return true;
        
        for (int i = 0; i < n; i++)
        {
            if (preorder[i] < low) return false;
            
            while (!s.empty() && preorder[i] > s.top())
            {
                low = s.top();
                s.pop();
            }
            
            s.push(preorder[i]);
        }
        
        return true;
    }
    

/* 2017-01-13, divide and conquer */

    bool verifyPreorder(vector<int>& preorder) {
        
        return _help(preorder, 0, preorder.size()-1, INT_MIN, INT_MAX);
    }
    
    bool _help(vector<int> &preorder, int l, int r, int mn, int mx)
    {
        if (l > r) return true;
        
        int val = preorder[l], i = 0;
        if (val <= mn || val >= mx) return false;
        
        for (i = l+1; i <= r; i++)
        {
            if (preorder[i] >= val) break;
        }
        
        return _help(preorder, l+1, i-1, mn, val) && _help(preorder, i, r, val, mx);
        
    }


/* wow! https://leetcode.com/discuss/51543/java-o-n-and-o-1-extra-space */
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN, index = -1;
        
        for (int i = 0; i < preorder.size(); i++)
        {
            if (preorder[i] < low) return false;
            
            while (index >= 0 && preorder[i] > preorder[index])
            {
                low = preorder[index--];
            }
            
            preorder[++index] = preorder[i];
        }
        
        return true;
    }
    
    


/* TLE */
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) return true;
        
        return _verify(preorder, 0, n-1);
    }
    
    bool _verify(vector<int> &preorder, int l, int r)
    {
        if (l >= r) return true;
        int root = preorder[l];
        int index = -1;
        for (int i = l+1; i <= r; i++)
        {
            if (preorder[i] > root) 
            {
                index = i;
                break;
            }
        }
        
        if (index == -1) return _verify(preorder, l+1, r);
        
        for (int i = index+1; i <= r; i++)
        {
            if (preorder[i] <= root) return false;
        }
        
        return _verify(preorder, l+1, index-1) && _verify(preorder, index, r);
    }  
