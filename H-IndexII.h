/*
  2015-09-06
  bluepp
  May the force be with me!
  
  Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
  https://leetcode.com/problems/h-index-ii/
*/

/* O(nlogn) */
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n-1;
        int index = 0;
        while (l <= r)
        {
            int m = l + (r-l)/2;
            
            int diff = n-m;
            if (citations[m] >= diff && index < diff)
            {
                index = diff;
            }
            else if (citations[m] < diff) l = m+1;
            else if (index >= diff) r = m-1;
        }
        
        return index;
    }



/* O(N) */
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            int diff = n-i;
            if (citations[i] >= diff && index < diff)
            {
                index = diff;
            }
        }
        
        return index;
    }
