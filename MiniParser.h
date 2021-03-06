/*
bluepp
2016-12-09
May the force be with me!

https://leetcode.com/problems/mini-parser/

Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
*/

    NestedInteger deserialize(string s) {
        
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        if (s.size() <= 2) return NestedInteger();
        
        NestedInteger res;
        int start = 1, cnt = 0;
        for (int i = 1; i < s.size(); ++i) {
            
            if (cnt == 0 && (s[i] == ',' || i == s.size() - 1)) {
                res.add(deserialize(s.substr(start, i - start)));
                start = i + 1;
            } else if (s[i] == '[') ++cnt;
            else if (s[i] == ']') --cnt;
        }
        
        return res;        
    }


/* 2017-02-12 */

    NestedInteger deserialize(string s) {
        
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> stk;
        
        int start = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                stk.push(NestedInteger());
                start = i+1;
            }
            else if (s[i] == ',' || s[i] == ']')
            {
                if (i > start)
                {
                    stk.top().add(NestedInteger(stoi(s.substr(start, i-start))));
                }
                
                start = i+1;
                
                if (s[i] == ']')
                {
                    if (stk.size() > 1)
                    {
                        NestedInteger t = stk.top();
                        stk.pop();
                        stk.top().add(t);
                    }
                }
            }
        }
        
        return stk.top();
    }
