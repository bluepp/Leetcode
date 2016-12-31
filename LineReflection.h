/*
bluepp
2016-06-19
May the force be with me!

https://leetcode.com/problems/line-reflection/

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given set of points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

*/

/* 2017-01-01, update */
    bool isReflected(vector<pair<int, int>>& points) {
        
        unordered_map<int, set<int>> map;
        int mn = INT_MAX, mx = INT_MIN;
        
        for (auto p : points)
        {
            mn = min(p.first, mn);
            mx = max(p.first, mx);
            map[p.first].insert(p.second);
        }
        
        
        double mid = (double)(mn+mx) /2;
        
        for (auto p : points)
        {
            int t = 2*mid - p.first;
            
            if (!map.count(t) || !map[t].count(p.second))
            {
                return false;
            }
        }
        
        return true;
    }

