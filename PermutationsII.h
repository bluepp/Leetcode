/*
    bluepp
    2014-06-19
    2014-07-19
    May the force be with me!
    
    Problem:    Permutations II
    Source:     https://oj.leetcode.com/problems/permutations-ii/
    Notes:
    Given a collection of numbers that might contain duplicates, return all possible unique permutations.
    For example,
    [1,1,2] have the following unique permutations:
    [1,1,2], [1,2,1], and [2,1,1].

    Solution: dfs...
 */
 
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> vec;
        vector<bool> avail(num.size(), true);
        sort(num.begin(), num.end());
        _perm(num, avail, vec, res);
        
        return res;
    }
    
    void _perm(vector<int> &num, vector<bool> &avail, vector<int>&vec, vector<vector<int> >&res)
    {
        if (vec.size() == num.size())
        {
            res.push_back(vec);
            return;
        }
        
        int lastindex = -1;
        for (int i = 0; i < num.size(); i++)
        {
            if (lastindex != -1 && num[i] == num[lastindex])
                continue;
            
            if (avail[i])
            {
                avail[i] = false;
                vec.push_back(num[i]);
                _perm(num, avail, vec, res);
                vec.pop_back();
                avail[i] = true;
                lastindex = i;
            }
            
        }
    }
