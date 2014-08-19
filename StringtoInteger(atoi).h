/*
    bluepp
    2014-06-26
    2014-07-27
    2014-08-19
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
