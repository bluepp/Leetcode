/*
bluepp
2017-03-28
May the force be with me!

https://leetcode.com/problems/minimum-time-difference/#/description

Given a list of 24-hour clock time points in "Hour:Minutes" format, 
find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.

*/

    int findMinDifference(vector<string>& timePoints) {
        
        int res = INT_MAX, n = timePoints.size(), diff = 0;
        sort(timePoints.begin(), timePoints.end());
        
        for (int i = 0; i < n; ++i) {
            string t1 = timePoints[i], t2 = timePoints[(i + 1) % n];
            int h1 = (t1[0] - '0') * 10 + t1[1] - '0';
            int m1 = (t1[3] - '0') * 10 + t1[4] - '0';
            int h2 = (t2[0] - '0') * 10 + t2[1] - '0';
            int m2 = (t2[3] - '0') * 10 + t2[4] - '0';
            diff = (h2 - h1) * 60 + (m2 - m1);
            if (i == n - 1) diff += 24 * 60;
            res = min(res, diff);
        }
        
        return res;
        
    }
