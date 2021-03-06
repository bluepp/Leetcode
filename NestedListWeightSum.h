/*
bluepp
2016-06-01
May the force be with me!

https://leetcode.com/problems/nested-list-weight-sum/
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
*/

class Solution {
public:

    int sum = 0, depth = 1;
    int depthSum(vector<NestedInteger>& nestedList) {
        
        for (auto p : nestedList)
        {
            if (p.isInteger())
            {
                sum += p.getInteger()*depth;
            }
            else
            {
                depth ++;
                depthSum(p.getList());
                depth--;
            }
        }
        
        return sum;
    }
    
    
    
/* 2016-09-11, update */
   int depthSum(vector<NestedInteger>& nestedList) {
        
        int ret = 0;
        
        for (auto p : nestedList)
        {
            ret += _sum(p, 1);
        }
        
        return ret;
    }
    
    int _sum(NestedInteger p, int level)
    {
        int ret = 0;
        
        if (p.isInteger())
        {
            return p.getInteger() * level;
        }
        else
        {
            for (auto a : p.getList())
            {
                ret += _sum(a, level+1);
            }
        }
        
        return ret;
    }    
