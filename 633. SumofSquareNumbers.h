/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
Seen this question in a real interview before?  

*/

    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c);
        
        while (a <= b) {
            int t = a*a + b*b;
            
            if (t == c) {
                return true;
            } else if (t < c) {
                a++;
            } else {
                b--;
            }
        }
        
        return false;
    }
