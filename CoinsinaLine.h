/*
  2015-10-03
  bluepp
  May the force be with me!
  
There are n coins in a line. Two players take turns to take one or two coins
from right side until there are no more coins left.
The player who take the last coin wins.

Could you please decide the first play will win or lose?

Example
n = 1, return true.
n = 2, return true.
n = 3, return false.
n = 4, return true.
n = 5, return true.

Challenge
O(n) time and O(1) memory
*/

/* Bash Game */
/* （n-1）%（m+1）==0 则后手胜利 */

     bool firstWillWin(int n) {
        // write your code here
        return n%3;
    }
