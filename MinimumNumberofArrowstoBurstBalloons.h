/*
bluepp
2016-12-10
May the force be with me!

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) 
and another arrow at x = 11 (bursting the other two balloons).
*/

/* 2017-03-07, update */

    int findMinArrowShots(vector<pair<int, int>>& points) {
        
        int n = points.size();
        if (n == 0) return 0;
        
        sort(points.begin(), points.end(), [&](pair<int, int> a, pair<int, int> b)
        {
            return a.first < b.first;
        });
        
        vector<pair<int, int>> res;
        pair<int, int> inter = points[0];
        
        for (int i = 1; i < n; i++)
        {
            if (inter.second < points[i].first) 
            {
                res.push_back(inter);
                inter = points[i];
            }
            else
            {
            //    inter.first = max(inter.first, points[i].first);
                inter.second = min(inter.second, points[i].second);
            }
        }
        
        res.push_back(inter);
        
        return res.size();
    }

   int findMinArrowShots(vector<pair<int, int>>& points) {
        
        if (points.empty()) return 0;
        sort(points.begin(), points.end());
        int res = 1, end = points[0].second;
        
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].first <= end) {
                end = min(end, points[i].second);
            } else {
                ++res;
                end = points[i].second;
            }
        }
        
        return res;
    }
