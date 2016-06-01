/*
bluepp
2016-06-01
May the force be with me!

https://leetcode.com/problems/top-k-frequent-elements/
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        
        if (nums.empty()) return res;
        
        unordered_map<int, int> map;
        for (auto p : nums)
        {
            map[p]++;
        }
        
        vector<pair<int, int>> heap;
        for (auto i : map)
        {
            heap.push_back({i.second, i.first});
        }
        make_heap(heap.begin(), heap.end());
        
        while (k--)
        {
            res.push_back(heap.front().second);
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
        
        return res;
    }
