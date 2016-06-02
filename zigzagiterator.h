/*
bluepp
2016-06-03
May the force be with me!

https://leetcode.com/problems/zigzag-iterator/

Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].

*/

class ZigzagIterator {
private:
    vector<int> vec1, vec2;
    bool first = true;
    int nextval;
    
public:
    

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vec1 = v1;
        vec2 = v2;
    }

    int next() {
       return nextval;
    }

    bool hasNext() {
        if (vec1.empty() && vec2.empty()) return false;
        
        if (vec1.empty())
        {
            nextval = vec2.front();
            vec2.erase(vec2.begin());
        }
        else if (vec2.empty())
        {
            nextval = vec1.front();
            vec1.erase(vec1.begin());
        }
        else
        {
            if (first)
            {
                nextval = vec1.front();
                vec1.erase(vec1.begin());
            }
            else
            {
                nextval = vec2.front();
                vec2.erase(vec2.begin());
            }
            
            first = !first;
        }
        
        return true;
        
    }
};
