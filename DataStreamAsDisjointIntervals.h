/*
bluepp
2016-06-08
May the force be with me!

https://leetcode.com/problems/data-stream-as-disjoint-intervals/

Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
*/

/* https://leetcode.com/discuss/105790/very-concise-c-solution */


class SummaryRanges {
private:
    vector<Interval> vec;
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        
        auto Cmp = [](Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), Cmp);
        int start = val, end = val;
        
        if (it != vec.begin() && (it-1)->end+1 >= val) it--;
        
        while (it != vec.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = vec.erase(it);
        }
        
        vec.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vec;
    }
};