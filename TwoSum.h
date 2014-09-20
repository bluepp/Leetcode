/*
    bluepp
    
    2014-06-30
    2014-07-31
    2014-08-17
    2014-09-03
    2014-09-20
    
    May the force be with me!
    
 
 Problem:    Two Sum
 Source:     https://oj.leetcode.com/problems/two-sum/
 Notes:
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 update, can use extra space, cannot use extra space
 http://www.mitbbs.com/mitbbs_article_t.php?board=JobHunting&gid=32517841&ftype=0
 

 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Solution: 1. Sort first. O(nlgn)
           2. Hash table. O(n)
           
 Note:  Hash Table solution has been updated.  In case that the two elements are the same, 
        all the indices should be stored in the map.
 */
 
 /* 2014-09-20, my version */
 
     vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vec;
        typedef unordered_map<int, int> MAP;
        MAP map;
        int n = numbers.size();
        int t1, t2;
        
        for (int i = 0; i < n; i++)
        {
            if (map.find(target-numbers[i]) != map.end())
            {
                t1 = i;
                t2 = map[target-numbers[i]];
                
                break;
            }
            
            map[numbers[i]] = i;
        }
        
        vec.push_back(min(t1, t2) + 1);
        vec.push_back(max(t1, t2) + 1);
        
        return vec;
        
    }
 
 
 
 
 
 /* my version */
     vector<int> twoSum(vector<int> &numbers, int target) {
        typedef unordered_map<int, int> MAP;
        MAP map;
        int n = numbers.size();
        int t1= 0, t2 = 0;
        
        for (int i = 0; i < n; i++)
        {
            
            if (map.find(target-numbers[i]) != map.end())
            {
                MAP:: iterator it = map.find(target-numbers[i]);
                t1 = i+1;
                t2 = it->second;
            }
            else
            {
                map[numbers[i]] = i+1;
            }
        }
        
        vector<int> res;
        res.push_back(min(t1, t2));
        res.push_back(max(t1, t2));
        
        return res;
    }
 
 
 
 /* sort */
 
     bool mycompare(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if (numbers.empty()) return res;
        
        vector<pair<int, int> > nums(numbers.size());
        for (int i = 0; i < numbers.size(); i++)
        {
            nums[i] = make_pair(numbers[i], i+1);
        }
    
        sort(nums.begin(), nums.end(), compare);
        
        int l = 0, r = numbers.size() -1;
        while (l < r)
        {
            int tmp = nums[l].first + nums[r].first;
            
            if (tmp == target) break;
            else if (tmp < target) l++;
            else r--;
        }
        
        res.push_back(min(nums[l].second, nums[r].second));
        res.push_back(max(nums[l].second, nums[r].second));
        
        return res;
    }
    
    
    
/* hash table , pay attantion duplicates */    
    
    typedef unordered_map<int, vector<int>> MAP;
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        MAP map;
        
        for (int i = 0; i < numbers.size(); i++)
            map[numbers[i]].push_back(i+1);
            
        int index1, index2;
        for (int i = 0; i < numbers.size(); i++)
        {
            MAP::iterator it = map.find(target - numbers[i]);
            if (it == map.end()) continue;
            
            index1 = it->second[0];
            index2 = i+1;
            
            if (numbers[i] == target - numbers[i])
            {
                if (it->second.size() == 1) continue;
                index2 = it->second[1];
            }
            
            break;
           
        }
        
        vector<int> res;
        res.push_back(min(index1, index2));
        res.push_back(max(index1, index2));
        
        return res;
        
       
     
     }
    
