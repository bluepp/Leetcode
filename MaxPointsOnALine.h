/* 
    2014-11-12
    2014-11-15
    bluepp
    May the force be with me!
    
     
 Problem:    Max Points On a Line
 https://oj.leetcode.com/problems/max-points-on-a-line/
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 Solution: ...
*/

/*2014-11-15, my version */
    int maxPoints(vector<Point> &points) {
        int ret = 0;
        int n = points.size();
        unordered_map<double, int> map;
        
        for (int i = 0; i < n; i++)
        {
            map.clear();
            int ss = 1, sp = 0;
            
            for (int j = i+1; j < n; j++)
            {
                double slope = 0.0;
                
                if (points[i].x != points[j].x)
                {
                    slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
                }
                else if (points[i].y == points[j].y)
                {
                    sp ++;
                    continue;
                }
                
                int tmp = 0;
                if (map.find(slope) != map.end())
                {
                    map[slope]++;
                    tmp = map[slope];
                }
                else
                {
                    tmp = map[slope] = 2;
                }
                
                ss = max(ss, tmp);
            }
            
            ret = max(ret, ss+sp);
        }
        
        return ret;
    }


    int maxPoints(vector<Point> &points) {
        int N = points.size(), res(0);
        unordered_map<double, int> m;
        for(int i = 0;i < N; ++i){
            m.clear();
            int ss(1), sp(0);                        // ss:points with same slope,starts with 1, sp:same points, starts with 0
            for(int j = i+1;j < N; ++j){
                double slope = std::numeric_limits<double>::infinity();
                if(points[i].x != points[j].x)
                    slope = 1.0*(points[i].y - points[j].y)/(points[i].x - points[j].x);
                else if(points[i].y == points[j].y){
                    sp++; continue;
                }
                int tmp = 0;
                if(m.find(slope) != m.end())
                    tmp = ++m[slope];
                else
                    tmp = m[slope] = 2;
                ss = max(ss,tmp);
            }
            res = max(res,ss+sp );
        }
        return res;
    }
    
