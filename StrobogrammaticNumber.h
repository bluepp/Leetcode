/*
  2015-08-11
  bluepp
  May the force be with me!
  
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic. The number is represented as a string.
For example, the numbers "69", "88", and "818" are all strobogrammatic.
https://leetcode.com/problems/strobogrammatic-number/
*/

    bool isStrobogrammatic(string num) {
        int n = num.size();
        if (n == 0) return true;
        if (n == 1) return is_801(num[0]);
        
        int l = 0, r = n-1;
        while (l <= r)
        {
            if (l == r)
            {
                return is_801(num[l]);
            }
            
            if (num[l] != num[r]) 
            {
                if ((num[l] == '6' && num[r] == '9') || (num[l] == '9' && num[r] == '6')) 
                {
                    l++; r--;
                }
                else return false;
            }
            else
            {
                if (is_801(num[l]) && is_801(num[r]))
                {
                    l++;
                    r--;
                }
                else return false;
            }
        }
        
        return true;
    }
    
    
    bool is_801(char c)
    {
        if (c == '8' || c == '0' || c== '1') return true;
        else return false;
    }
