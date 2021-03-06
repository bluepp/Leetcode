/*
  2015-09-06
  bluepp
  May the force be with me!
  
Given an array of citations (each citation is a non-negative integer) of a researcher,
write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia:
"A scientist has index h if h of his/her N papers have at least h citations each,
and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers
in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each,
his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
https://leetcode.com/problems/h-index/
*/

/* 2016-06-27, update */

    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end(), greater<int>());
        
        for (int i = 0; i < citations.size(); i++)
        {
            if (i >= citations[i])
            {
                return i;
            }
        }
        
        return citations.size();
        
    }



/* O(nlogn) time, O(1)space */
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        
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

/* O(N)time, O(N) space */
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int count[n+1];
        memset(count, 0, sizeof(count));
        
        for (auto c : citations)
        {
            if (c > n) count[n]++;
            else count[c]++;
        }
        
        int total = 0;
        for (int i = n; i >= 0; i--)
        {
            total += count[i];
            if (total >= i) return i;
        }
        
        return 0;
    }
