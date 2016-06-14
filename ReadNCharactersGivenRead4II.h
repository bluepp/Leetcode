/*
  2015-07-16
  bluepp
  May the force be with me!
  
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. 
For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.
*/

/* http://www.cnblogs.com/EdwardLiu/p/4240616.html */
/* 2016-06-14, update */
/* what is the difference between call one time and call multi times? */
/*
https://leetcode.com/discuss/84216/what-the-difference-between-call-once-and-call-multiple-times

Think that you have 4 chars "a, b, c, d" in the file, and you want to call your function twice like this:

read(buf, 1); // should return 'a'
read(buf, 3); // should return 'b, c, d'
All the 4 chars will be consumed in the first call. 
So the tricky part of this question is how can you preserve the remaining 'b, c, d' to the second call.
*/

/* https://leetcode.com/discuss/21219/a-simple-java-code */


int read4(char *buf);

class Solution {
private:
    int buffCnt;
    int buffPtr;
    char buff[5];
    
public:
    Solution() : buffCnt(0), buffPtr(0) {}
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        
        int cnt = 0;
        
        while(cnt<n)
        {
        
            if(buffPtr==0)
            {
                buffCnt = read4(buff);
            }
            
                
            if(buffCnt==0)  break;
            
            while(cnt<n && buffPtr<buffCnt)
            {
                buf[cnt++] = buff[buffPtr++];
            }
            
            if(buffPtr==buffCnt) 
            {
                buffPtr=0;
            }
        }
        
        return cnt;
    }

