/*
  bluepp
  2015-07-14
  May the force be with me!
  
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

https://leetcode.com/problems/number-of-digit-one/
*/

/* recursion, https://leetcode.com/discuss/54107/0-ms-recursive-solution */
    int countDigitOne(int n) {
        if (n < 1) return 0;
        if (n >= 1 && n < 10) return 1;
        
        int y = 1, x = n;
        while (x >= 10)
        {
            x /= 10;
            y *= 10;
        }
        
        if (x == 1) return n-y+1+countDigitOne(y-1)+ countDigitOne(n%y);
        else return y +x*countDigitOne(y-1)+countDigitOne(n%y);
    }



/* https://leetcode.com/discuss/45274/share-my-o-lgn-c-solution-to-number-of-digit-one?show=45274#q45274 */
    int countDigitOne(int n) {
        long long base = 1, res = 0, last = 0;
        
        while (n >= base)
        {
            int index = (n / base) % 10;
            long long remain = n - (n/base)*base;
            
            if (index > 1)
            {
                res = res + index*last+base;
            }
            else if (index == 1)
            {
                res = res+index*last + remain+1;
            }
            else
            {
                res = res + index * last;
            }
            
            last = last*10 + base;
            base = base*10;
        }
        
        return res;
    }
    
    
/* Follow Up: you can change the code to meet the new problem Number of Digit K, such as Number of Digit 3 */


int countDigitK(int n, int k) {
    long long base = 1, res = 0, last = 0;
    while(n >= base){
        int index = (n / base) % 10;
        long long remain = n - (n / base) * base;
        if(index > k){
            res = res + index * last + base;
        }else if(index == k){
            res = res + index * last + remain + 1;
        }else{
            res = res + index * last;
        }
        last = last * 10 + base;
        base = base * 10;
    }
    return res;
}

