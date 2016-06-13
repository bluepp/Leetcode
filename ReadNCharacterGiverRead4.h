/*
  2014-12-13
  bluepp
  May the force be with me!
  
  https://oj.leetcode.com/problems/read-n-characters-given-read4/
  
  Read N Characters Given Read4 Total Accepted: 631 Total Submissions: 2557 My Submissions Question Solution 
  The API: int read4(char *buf) reads 4 characters at a time from a file.

  The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

  By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
*/

/* 2016-06-14, update */
    int read(char *buf, int n) {
        
        if (n <= 0) return n;
        int bytes = 0, totalBytes = 0;
        
        while (true) {
            bytes = read4(buf + totalBytes);
            totalBytes += bytes;
        
            if (bytes == 0) return totalBytes; // end of file
            if (totalBytes >= n) return n; // we have read what we were expected to read
        }
    }




// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        
        char *pBuf = buf;
       
        int len = 0;
        int size = 0;
        while (len <= n && ((size = read4(pBuf)) > 0))
        {
            size = len+size > n ? n-len : size;
            len += size;
            pBuf += size;
            
        }
        
        return len;

    }
};
