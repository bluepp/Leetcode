/*
  bluepp
  2016-08-25
  May the force be with me!
  
  https://leetcode.com/problems/first-unique-character-in-a-string/
  
  Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

    int firstUniqChar(string s) {
        int ret = -1;
        
        unordered_map<char, int> map;
        for (auto p : s) {
            map[p]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] == 1) {
                ret = i;
                break;
            }
        }
        
        return ret;
    }
