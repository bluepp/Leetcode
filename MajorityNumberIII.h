/*
  2015-09-04
  bluepp
  May the force be with me!
  
Medium Majority Number III Show result 

Given an array of integers and a number k,
the majority number is the number that occurs more than 1/k of the size of the array.
Find it.

Have you met this question in a real interview? Yes
Example
Given [3,1,2,3,2,3,3,4,4,4] and k=3, return 3.

Note
There is only one majority number in the array.

Challenge
O(n) time and O(k) extra space
http://www.lintcode.com/en/problem/majority-number-iii/#
*/

    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> map;
        
        for (auto p : nums)
        {
            if (map.count(p))
            {
                map[p]++;
            }
            else
            {
                if (map.size() >= k)
                {
                    for (auto t : map)
                    {
                        t.second--;
                        if (t.second == 0) map.erase(t.first);
                    }
                }
                
                map[p] = 1;
            }
        }
        
        int res = 0, count = 0;
        for (auto p : map)
        {
            if (p.second > count)
            {
                res = p.first;
                count = p.second;
            }
        }
        
        return res;
    }
