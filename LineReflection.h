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
/* https://leetcode.com/discuss/109028/concise-o-n-c-solution */

struct hashFunc {
    
    size_t operator()(const pair<int, int> &point) const
    {
        return point.first * 31 + point.second;
    }
};


class Solution {
    
public:
    bool isReflected(vector<pair<int, int>>& points) {
        
        if (points.size() <= 1) return true;
        unordered_set<pair<int, int>, hashFunc> points_set;
        
        int xmin = numeric_limits<int>::max();
        int xmax = numeric_limits<int>::min();
        
        for (auto point : points) {
            
            xmin = min(xmin, point.first);
            xmax = max(xmax, point.first);
            
            points_set.emplace(point);
        }
        
        for (auto point : points_set) {
            
            if (!points_set.count(make_pair(xmax + xmin - point.first, point.second)))
                return false;
        }
        return true;
    }

