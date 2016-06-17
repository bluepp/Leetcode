/*
  2015-06-17
  bluepp
  May the force be with me!
  
Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).

https://leetcode.com/problems/reverse-bits/
*/

/* 2016-06-17, update */

    uint32_t reverseBits(uint32_t n) {
        
        int ret = 0;
        
        for(int i = 0; i < 32; i++)
        {
            ret |= ((n >> i) & 1) << (31-i);
        }
        
        return ret;
    }



    uint32_t reverseBits(uint32_t n) {
        
        if (n == 0) return 0;
        
        uint32_t ret = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
            {
                ret=ret+(0x80000000>>i);
            }
        }
        
        return ret;
    }
