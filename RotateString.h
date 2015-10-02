/*
  2015-10-02
  bluepp
  May the force be with me!
  
Given a string and an offset, rotate string by offset. (rotate from left to right)

Have you met this question in a real interview? Yes
Example
Given "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
Challenge
Rotate in-place with O(1) extra memory.

http://www.lintcode.com/en/problem/rotate-string/#
*/

   void rotateString(string &str,int offset){
        //wirte your code here
        if (!str.empty()) {
            
            offset %= str.length();
            reverse(str.begin(), str.begin() + str.length() - offset);
            reverse(str.begin() + str.length() - offset, str.end());
            reverse(str.begin(), str.end());
        }
    
    }
  
