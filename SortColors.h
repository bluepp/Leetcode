/*
    bluepp
    
    2014-06-24
    2014-07-26
    2014-08-20
    2014-09-16
    2014-09-29
    
    May the for be with me!
    
    
 Problem:    Sort Colors
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/sort-colors/
 Notes:
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color
 are adjacent, with the colors in the order red, white and blue.
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 Note:
 You are not suppose to use the library's sort function for this problem.
 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with 
 total number of 0's, then 1's and followed by 2's.
 Could you come up with an one-pass algorithm using only constant space?

 Solution: 0 0 0 1 1 1 1 ...... 2 2 2 2
               |         |      |
             zero        i     two
              ->        ->     <-  
 */
 
 http://en.wikipedia.org/wiki/Dutch_national_flag_problem
 
    void sortColors(int A[], int n) {
        int p = -1, q = n;
        
        for (int i = 0; i < q;)
        {
            switch(A[i])
            {
                case 0:
                    swap(A[i++], A[++p]);
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    swap(A[i], A[--q]);
                    break;
            }
        }
    }
