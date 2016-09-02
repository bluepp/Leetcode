/*
  2015-08-11
  bluepp
  May the force be with me!
  
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.

https://leetcode.com/problems/meeting-rooms/
*/


/* 2016-09-03, update */

    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)
        {
            return a.start < b.start;
        });
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i-1].end)
            {
                return false;
            }
        }
        
        return true;
    }





bool mycompare (Interval a, Interval b)
{
    return a.start < b.start;
}
 
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        int n = intervals.size();
        if (n == 0 || n == 1) return true;
        
        sort(intervals.begin(), intervals.end(), mycompare);
        
        for (int i = 1; i < n; i++)
        {
            if (intervals[i].start < intervals[i-1].end) return false;
        }
        
        return true;
    }
};
