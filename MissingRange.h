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
        if (n == 0)
        {
            string str = getrange(lower, upper);
            res.push_back(str);
            return res;
        }
        
        int start = INT_MAX, end = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            end = A[i]-1;
            
            if (end > upper || start > upper || end < lower || start < lower) break;
            if (start > end) continue;
            
            string str = getrange(start, end);
            res.push_back(str);
            
            start = A[i]+1;
        }
        
        return res;
    }
    
    string getrange(int start, int end)
    {
        string str;
        if (start == end)
        {
            str.push_back(start+'0');
        }
        else
        {
            //str.push_back(start+'0');
            //str.push_back('-');
            //str.push_back('>');
            //str.push_back(end+'0');
            char t = 'a';
            str = '3';
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
