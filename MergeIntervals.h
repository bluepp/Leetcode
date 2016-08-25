/*
    bluepp
    
    2014-06-14
    2014-07-16
    2014-09-14
    2014-09-23
    2014-10-16
    2014-11-16
    
    May the force be with me!
    
    Problem:    Merge Intervals
    Source:     https://oj.leetcode.com/problems/merge-intervals/
    Notes:
    Given a collection of intervals, merge all overlapping intervals.
    For example,
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18].

    Solution: 1. Sort in ascending order of 'start'.
              2. Traverse the 'intervals', merge or push...
*/

/* 2016-08-26 , update */
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval> res;
        int n = intervals.size();
        if (n == 0)
        {
            return res;
        }
        
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b)
        {
            return a.start < b.start;
        });
        
        Interval newinterval = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (newinterval.end < intervals[i].start)
            {
                res.push_back(newinterval);
                newinterval = intervals[i];
            }
            else if (intervals[i].end < newinterval.start)
            {
                res.push_back(intervals[i]);
            }
            else
            {
                newinterval.start = min(newinterval.start, intervals[i].start);
                newinterval.end = max(newinterval.end, intervals[i].end);
            }
        }
        
        res.push_back(newinterval);
        
        return res;
    }


/* 2014-11-16 , my version */
bool mycompare(Interval a, Interval b)
 {
     return a.start < b.start;
 }
 

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        
        vector<Interval> res;
        int n = intervals.size();
        if (n == 0 || n == 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), mycompare);
        
        Interval tmp = intervals[0];
        
        for (int i = 1; i < n; i++)
        {
            if (tmp.end < intervals[i].start)
            {
                res.push_back(tmp);
                tmp = intervals[i];
            }
            else
            {
                tmp.start = min(tmp.start, intervals[i].start);
                tmp.end = max(tmp.end, intervals[i].end);
            }
        }
        
        res.push_back(tmp);
        
        return res;
    }
};



--------------------------------------------------------





 bool mycompare(Interval a, Interval b)
    {
        return a.start < b.start;
    }
 
 
class Solution {
public:
   
    
    vector<Interval> merge(vector<Interval> &intervals) {
        
        vector<Interval> res;
        int n = intervals.size();
        if (n == 0 || n == 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), mycompare);
        
        Interval tmp = intervals[0];
        for (int i = 1; i < n; i++)
        {
            if (tmp.end < intervals[i].start)   
            {
                res.push_back(tmp);
                tmp = intervals[i];
            }
            else if (tmp.start > intervals[i].end)
            {
                res.push_back(tmp);
            }
            else
            {
                tmp.start = min(tmp.start, intervals[i].start);
                tmp.end = max(tmp.end, intervals[i].end);
            }
            
        }
        
        res.push_back(tmp);
        return res;
        
    }
    
    
    -----------------------
        
        second?
