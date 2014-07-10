/*
    bluepp
    2014-06-08
    2014-07-10
    May the force be with you!
    
    Problem:    First Missing Positive
    Source:     https://oj.leetcode.com/problems/first-missing-positive/
    Notes:
    Given an unsorted integer array, find the first missing positive integer.
    For example,
    Given [1,2,0] return 3,
    and [3,4,-1,1] return 2.
    Your algorithm should run in O(n) time and uses constant space.

    Solution: Although we can only use constant space, we can still exchange elements within input A!
           Swap elements in A and try to make all the elements in A satisfy: A[i] == i + 1.
           Pick out the first one that does not satisfy A[i] == i + 1.
 */
 
     int firstMissingPositive(int A[], int n) {
        
        int i = 0;
        while (i < n)
        {
            //find the position for each element, kind like sort it, but much fast
            if (A[i] >= 0 && A[i] < n && A[A[i]] != A[i])
            {
                swap(A[i], A[A[i]]);
                continue;
            }

            ++i;
        }

        int j = 1;
        while(j < n && A[j] == j)
            j++;
	
	    //fisrt element maybe n, if so, the largest missed positive number should be n+1
	    if (A[0] == j)
	        ++j;

        return j;

    }
