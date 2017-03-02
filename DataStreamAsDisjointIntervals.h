/*
bluepp
2016-06-08
May the force be with me!

https://leetcode.com/problems/data-stream-as-disjoint-intervals/

Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
*/

/* 2017-03-02, my version, update */

class SummaryRanges {
private:
    vector<Interval> vec;


public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        
        vector<Interval> res;
        
        Interval v(val, val);
        bool insert = false;
        
        for(auto p : vec)
        {
            if (p.start <= v.start && v.end <= p.end)
            {
                res.push_back(p);
                insert = true;
            }
            else if (p.end <= v.start)
            {
                if (p.end+1 == v.start || p.end == v.start) v.start = p.start;
                else
                {
                    res.push_back(p);
                }
            }
            else if (v.end <= p.start)
            {
                if (v.end+1 == p.start || v.end == p.start) v.end = p.end;
                else
                {
                    if (!insert) res.push_back(v);
                    res.push_back(p);
                    insert = true;
                }
            }
        }
        
        if (!insert) res.push_back(v);
        
        vec = res;
     
    }
    
    vector<Interval> getIntervals() {
        
        return vec;
       
    }



/* https://leetcode.com/discuss/105790/very-concise-c-solution */


class SummaryRanges {
private:
    vector<Interval> v;
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        
        Interval cur(val, val);
        vector<Interval> res;
        int pos = 0;
        for (auto a : v) {
            if (cur.end + 1 < a.start) {
                res.push_back(a);
            } else if (cur.start > a.end + 1) {
                res.push_back(a);
                ++pos;
            } else if (cur.start - 1 == a.end) {
                cur.start = a.start;
            } else if (cur.end + 1 == a.start) {
                cur.end = a.end;
            } else {
                cur.start = min(cur.start, a.start);
                cur.end = max(cur.end, a.end);
            }
        }
        res.insert(res.begin() + pos, cur);
        v = res;
        
    }
    
    vector<Interval> getIntervals() {
        
        return v;
    }
};
