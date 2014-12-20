/*
  bluepp
  
  2014-12-12
  2014-12-20
  
  May the force be with me!
  
  https://oj.leetcode.com/problems/missing-ranges/
  Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

  For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/  


/* 2014-12-20 */
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        
        vector<string> res;
        
        int last = lower-1;
        for (int i = 0; i < n; i++)
        {
            _addrange(last+1, A[i]-1, res);
            last = A[i];
        }
        
        _addrange(last+1, upper, res);
        
        return res;
    }
    
    void _addrange(int l, int r, vector<string> &res)
    {
        string buf = "";
        
        if (r < l) return;
        else if (r == l) buf += to_string(l);
        else 
        {
            buf += to_string(l);
            buf += "->";
            buf += to_string(r);
        }
        
        res.push_back(buf);
    }




/* http://www.danielbit.com/blog/puzzle/leetcode/leetcode-missing-ranges */
/*https://changhaz.wordpress.com/ */
/* wrong, need to fix */
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> res;
        if (n == 0)
        {
            string str = getrange(lower, upper);
            res.push_back(str);
            return res;
        }
        
        int start = lower, end = upper;
        for (int i = 0; i < n; i++)
        {
            if (i == n-1)
            {
                start = A[i]+1;
            }
            
            
            end = A[i]-1;
            
            if (end > upper || start > upper || end < lower || start < lower) continue;
            if (start > end) continue;
            
            string str = getrange(start, end);
            res.push_back(str);
            
            start = A[i]+1;
        }
        
        return res;
    }
    
    string getrange(int start, int end)
    {
        string str = "";
        if (start == end)
        {
            str += to_string(start);
        }
        else
        {
           str += to_string(start);
           str += "->";
           str += to_string(end);
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
