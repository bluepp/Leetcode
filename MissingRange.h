/*
  bluepp
  
  2014-12-12
  
  May the force be with me!
  
  https://oj.leetcode.com/problems/missing-ranges/
  Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

  For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/  

/* http://www.danielbit.com/blog/puzzle/leetcode/leetcode-missing-ranges */
/* wrong, need to fix */
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> res;
        
        int prev = lower-1;
        for (int i = 0; i <= n; i++)
        {
            int curr = (i == n) ? upper+1 : A[i];
            
            if (curr-prev >= 2)
            {
                string str = _getrange(prev+1,curr-1);
                res.push_back(str);
            }
            
            prev = curr;
        }
        
        return res;
    }
    
    string _getrange(int from, int to)
    {
        string str;
        if (from == to)
        {
            str.push_back(from);
        }
        else
        {
            str.push_back(from);
            str += "->";
            str.push_back(to);
        }
        
        return str;
    }




/* TLE */
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> res;
        string str;
        
        int k = 0;
        for (int i = lower; i <= upper; i++)
        {
            if (A[k] == i)
            {
                if (!str.empty()) 
                {
                    res.push_back(str);
                    str.clear();
                }
                if (k < n-1) k++;
                continue;
            }
            
            if (str.size() == 1) str +="->";
            if (str.size() > 1) str.pop_back();
            str.push_back(i);
        }
        
        return res;
        
    }
