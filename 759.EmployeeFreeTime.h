/*
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Note:

schedule and schedule[i] are lists with lengths in range [1, 50].
0 <= schedule[i].start < schedule[i].end <= 10^8.
*/


    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        
        vector<Interval> res, v;
        
        for (auto p : schedule){
            v.insert(v.end(), p.begin(), p.end());
        }
        
        sort(v.begin(), v.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        
        Interval t = v[0];
    
        for (Interval i : v) {
            if (t.end < i.start) {
                res.push_back(Interval(t.end, i.start));
                t = i;
            } else {
                t = (t.end < i.end) ? i : t;
            }
        }
       
        return res;

    }



/* wrong version */
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
       
        vector<Interval> res, cache, cache1;
        int n = schedule.size();
        if (n < 2){
            return res;
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < schedule[i].size(); j++){
                cache.push_back(schedule[i][j]);
            }
        }
       
        sort(cache.begin(), cache.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        
        Interval interval = cache[0];
        for(int i = 1; i < cache.size(); i++){
            if (interval.end < cache[i].start){
                cache1.push_back(interval);
            } else{
                interval.start = min(interval.start, cache[i].start);
                interval.end = max(interval.end, cache[i].end);
            }
        }
        
        cache1.push_back(interval);
        
        if (cache1.size() < 2){
            return res;
        }
        
        for (int i = 1; i < cache1.size(); i++){
            Interval gap;
            gap.start = cache1[i-1].end;
            gap.end = cache1[i].start;
            
            res.push_back(gap);
        }
        
        return res;
    }
