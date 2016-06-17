/*
bluepp
2016-06-17
May the force be with me!

https://leetcode.com/problems/number-of-1-bits/

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

/* 1 */
    int hammingWeight(uint32_t n) {
    
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = 1 << i;
            if (n & bit)
            {
                count++;
            }
        }
        
        return count;
    }
    
    
/* 2 , https://leetcode.com/discuss/70718/use-n-n%26-n-1-trick-to-clear-the-least-bit  */
public int hammingWeight(int n) {
    int result = 0;
    while(n!=0){
        n = n & (n-1);
        result++;
    }
    return result;
}
