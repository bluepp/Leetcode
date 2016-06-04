/*
bluepp
2016-06-04
May the force be with me!

https://leetcode.com/problems/flatten-nested-list-iterator/

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/

/* with stack */
class NestedIterator {
private:    
    stack<pair<const vector<NestedInteger>*, int>> s;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList)  {
        if (nestedList.size() > 0)
            s.push(make_pair(&nestedList, 0));
    }

    int next() {
        hasNext();
        pair<const vector<NestedInteger>*, int>& p = s.top();
        
        int result = (*p.first)[p.second++].getInteger();
        return result;  
    }

    bool hasNext() {
        if (s.empty())  return false;

        pair<const vector<NestedInteger>*, int>& p = s.top();
        if ((*p.first).size() == 0 || (*p.first).size() == p.second) {
            s.pop();
        return hasNext();
        }

        if ((*p.first)[p.second].isInteger())
            return true;

        s.push(make_pair(&(*p.first)[p.second++].getList(), 0));
        return hasNext();
    }
};
