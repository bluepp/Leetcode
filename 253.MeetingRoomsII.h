/*
  2015-08-11
  bluepp
  May the force be with me!
  
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

https://leetcode.com/problems/meeting-rooms-ii/
*/

    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto a : intervals) {
            ++m[a.start];
            --m[a.end];
        }
        int rooms = 0, res = 0;
        for (auto it : m) {
            res = max(res, rooms += it.second);
        }
        return res;
    }




/* TLE, MY version */
bool mycompare(Interval a, Interval b) 
{
    return a.start < b.start;
}
 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0 || n == 1) return n;
        
        sort(intervals.begin(), intervals.end(), mycompare);
        
        int t = 0, tmin = INT_MAX;
        for (int i = intervals[0].start; i <= intervals[n-1].end; i++)
        {
            if (isstart(i, intervals)) t++;
            tmin = max(tmin, t);
            if (isend(i, intervals)) t--;
        }
        
        return tmin;
    }
    
    bool isstart(int n, vector<Interval> &intervals)
    {
        for (int i = 0; i < intervals.size(); i++)
        {
            if (n == intervals[i].start) return true;
        }
        
        return false;
    }
    
    bool isend(int n, vector<Interval> &intervals)
    {
        for (int i = 0; i < intervals.size(); i++)
        {
            if (n == intervals[i].end) return true;
        }
        
        return false;
    }
