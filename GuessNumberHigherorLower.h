/*
bluepp
2016-07-17
May the force be with me!

https://leetcode.com/problems/guess-number-higher-or-lower/

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
*/

/* 2016-08-28, update */
    int guessNumber(int n) {
        
        int l = 1, r = n;
        while (l <= r)
        {
            int m = l + (r-l)/2;
            int t = guess(m);
            
            if (t == 0)
            {
                return m;
            }
            else if (t == -1)
            {
                r = m-1;
            }
            else 
            {
                l = m+1;
            }
        }
        
        return -1;
    }
