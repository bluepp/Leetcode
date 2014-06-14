/*
    bluepp
    2014-06-14
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


bool mycompare(Interval a, Interval b)
{
    return a.start < b.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), mycompare);
        vector<Interval> res;
        Interval last = intervals[0];
        
        for (int i = 1; i < n; ++i) 
        {
            if (intervals[i].start > last.end) {
                res.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        }
        res.push_back(last);
        return res;
       
    }
};
