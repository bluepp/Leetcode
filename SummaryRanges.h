/*
  2015-06-29
  bluepp
  May the force be with me!
  
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

*/

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        int n = nums.size();
        if (n == 0) return res;
        
        string s;
        s += to_string(nums[0]);
        if (n == 1)
        {
            res.push_back(s);
            return res;
        }
        
        for (int i = 1; i < n; i++)
        {
            if ((long long)nums[i]-(long long )nums[i-1] > 1)
            {
                res.push_back(s);
                s.clear();
            }
            else
            {
                size_t t = s.find('>');
                if (t == string::npos)
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
