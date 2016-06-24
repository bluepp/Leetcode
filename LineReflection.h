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

    bool isReflected(vector<pair<int, int>>& points) {
        
        unordered_map<int, set<int>> m;
        int mx = INT_MIN, mn = INT_MAX;
        for (auto a : points) {
            mx = max(mx, a.first);
            mn = min(mn, a.first);
            m[a.first].insert(a.second);
        }
        double y = (double)(mx + mn) / 2;
        for (auto a : points) {
            int t = 2 * y - a.first;
            if (!m.count(t) || !m[t].count(a.second)) {
                return false;
            }
        }
        return true;
        
    }

