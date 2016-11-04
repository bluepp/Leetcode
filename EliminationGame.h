/*
2016-11-05
bluepp
May the force be with me!

https://leetcode.com/problems/elimination-game/

There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/

    int lastRemaining(int n) {
        
        return _remain(n, true);
    }
    
    int _remain(int n, bool left2right)
    {
        if (n == 1) return 1;
        if (left2right) return 2 * _remain(n/2, false);
        else return 2 * _remain(n/2, true)-1 + n%2;
    }
