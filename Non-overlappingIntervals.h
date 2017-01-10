/*
2016-11-05
bluepp
May the force be with me!

https://leetcode.com/problems/non-overlapping-intervals/

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

/* 2017-01-11, update, remove the interval with larger end point */

    int eraseOverlapIntervals(vector<Interval>& intervals) {
        
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), [&](Interval a, Interval b)
        {
            return a.start < b.start;
        });
        
        int ret = 0;
        int maxend = intervals[0].end;
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < maxend)
            {
                ret ++;
                maxend = min(intervals[i].end, maxend);
            }
            else
            {
                maxend = intervals[i].end;
            }
        }
        
        return ret;
    }


    int eraseOverlapIntervals(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)
        {
            return a.start < b.start;
        });
        
        int ret = 0;
        int last = 0;
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[last].end) 
            {
                ret ++;
                if (intervals[i].end < intervals[last].end) last = i;
            }
            else last = i;
        }
        
        return ret;
        
    }
