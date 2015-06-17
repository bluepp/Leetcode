/*
  2015-06-17
  bluepp
  May the force be with me!
  
Largest Number Total Accepted: 21003 Total Submissions: 133834 My Submissions Question Solution 
Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

https://leetcode.com/problems/largest-number/
*/

    string largestNumber(vector<int>& nums) {
         vector<string> arr;  
          
        //将num转成string存入数组  
        for(int i : nums)  
            arr.push_back(to_string(i));  
              
        //比较排序  
        sort(arr.begin(), arr.end(), compare);  
          
        //连接成字符串  
        string ret;  
        for(string s : arr)  
            ret += s;  
          
        //排除特殊情况  
        if(ret[0] == '0' && ret.size() > 0)   
            return "0";  
          
        return ret;  
    }
    
    static bool compare(string &s1, string &s2)  
    {  
        return s1 + s2 > s2 + s1;  
    }  
