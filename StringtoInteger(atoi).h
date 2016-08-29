/*
    bluepp
    2014-06-26
    2014-07-27
    2014-08-19
    2014-08-27
    May the force be with me!
    
   
 Problem:    String to Integer (atoi)
 Leetcode.com/problems/string-to-integer-atoi/
 Notes:
 Implement atoi to convert a string to an integer.
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not 
 see below and ask yourself what are the possible input cases.
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
 You are responsible to gather all the input requirements up front.

 Requirements for atoi:
 The function first discards as many whitespace characters as necessary until the first 
 non-whitespace character is found. Then, starting from this character, takes an optional
 initial plus or minus sign followed by as many numerical digits as possible, and interprets 
 them as a numerical value.
 The string can contain additional characters after those that form the integral number, which 
 are ignored and have no effect on the behavior of this function.
 If the first sequence of non-whitespace characters in str is not a valid integral number, or 
 if no such sequence exists because either str is empty or it contains only whitespace characters, 
 no conversion is performed.
 If no valid conversion could be performed, a zero value is returned. If the correct value is out 
 of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

 Solution: ...
 */
 
 /* 2016-08-29, update */
 
     int myAtoi(string str) {
        
        if (str.empty())
        {
            return 0;
        }
        
        int i = 0;
        while (i < str.length() && str[i] == ' ')
        {
            i++;
        }
        
        bool positive = true;
        if (str[i] == '+' || str[i] == '-')
        {
            if (str[i] == '-')
            {
                positive = false;
            }
            
            i++;
        }
        
        
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        
        
        int ret = 0;
        while (i < str.length() && str[i] <= '9' && str[i] >= '0')
        {
            if (ret > INT_MAX/10 || ret == INT_MAX/10 && str[i]-'0' >= 8)
            {
                return positive ? INT_MAX : INT_MIN;
            }
            
            ret = ret * 10 + str[i]-'0';
            i++;
        }
        
        return positive ? ret : -ret;
       
    }
    
    

/* 2016-06-14, update */
/* https://leetcode.com/discuss/98230/my-8ms-c-solution-8-lines     */

   int myAtoi(string str) {
        
        long result = 0;
        bool negative = false;
        
        int i = str.find_first_not_of(' ');
        
        if (str[i] == '-') 
        {
            negative = true;
            i++;
        }
        else if (str[i] == '+')
        {
            i++;
        }
        
        for (int n = i; i - n <= 10 && isdigit(str[i]); i++)
        {
            result = result * 10 + (str[i]-'0');
        }
        
        if (negative)
        {
            result = -result;
        }
        
        return (result > INT_MAX ? INT_MAX : (result < INT_MIN ? INT_MIN : result));
 
    }





    int atoi(const char *str) {
        if (!str) return 0;
        const char *p = str;
        while (*p == ' ') p++;
        bool neg = false;
        
        if (*p == '+' || *p == '-')
        {
            if (*p == '-') neg = true;
            p++;        }
        
        long long num = 0;
        while(isdigit(*p))
        {
            num = num *10 + (*p -'0');
            p++;
        }
        
        num = neg ? -num : num;
        
        if (num > INT_MAX) num = INT_MAX;
        if (num < INT_MIN) num = INT_MIN;
        
        return (int)num;
    }
