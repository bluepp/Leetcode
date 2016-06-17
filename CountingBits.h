/*
bluepp
2016-06-01
May the force be with me!

https://leetcode.com/problems/counting-bits/

Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/

/*
https://leetcode.com/discuss/105490/cute-lovely-simple-c-solution
Because for an integer i, 
when i/2 equals to the bit representation of i shift right for one bit. 
So it's r[i/2]. And we just need to add i%2 which is the most right hand side of the bit set.
*/

    vector<int> countBits(int num) {
       
       vector<int> res;
       
       res.push_back(0);
       
       for (int i = 1; i <= num; i++)
       {
           int x = res[i/2] + (i%2);
           res.push_back(x);
       }
       
       return res;
    }
    
/* 2016-06-17,  */
    vector<int> countBits(int num) {
       
       vector<int> res;
       
       res.push_back(0);
       
       for (int i = 1; i <= num; i++)
       {
           int x = res[i >> 1] + (i & 1);
           res.push_back(x);
       }
       
       return res;
    }
