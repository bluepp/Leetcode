/*
  2015-06-29
  bluepp
  May the force be with me!
  
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

*/


/* 2017-01-19, update */
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> res;
        string str;
        int n = nums.size();
        if (n == 0) return res;
        
        nums.push_back(INT_MAX);
        str += to_string(nums[0]);
        
        for (int i = 1; i < n+1; i++)
        {
            if (nums[i]-nums[i-1] != 1)
            {
                if (to_string(nums[i-1]) != str)
                {
                    str += "->";
                    str += to_string(nums[i-1]);
                }
                
                res.push_back(str);
                
                str.clear();
                str += to_string(nums[i]);
            }
        }
        
        return res;
        
    }





/* 2016-06-26 , update */
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> res;
        int i = 0, n = nums.size();
        
        while (i < n)
        {
            int j = 1;
            
            while (i+j < n && nums[i+j]-nums[i] == j)
            {
                j++;
            }
            
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i+j-1]));
            
            i += j;
        }
        
        return res;
        
    }




    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        int n = nums.size();
        if (n == 0) return res;
        
        string s = "";
        s += to_string(nums[0]);
        
        for (int i = 1; i < n; i++)
        {
            if ((long long)nums[i] - (long long)nums[i-1] > 1)
            {
                res.push_back(s);
                s.clear();
            }
            else
            {
                int t = s.find('>');
                if (t == string :: npos)
                {
                    s += "->";
                }
                else
                {
                    s.erase(t+1, string::npos);
                }
            }
            
            s += to_string(nums[i]);
        }
        
        res.push_back(s);
        return res;
    }
