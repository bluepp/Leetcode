/*
bluepp
2016-08-25
May the force be with me!

https://leetcode.com/problems/ransom-note/

 Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   

Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> map;
        
        for (auto p : magazine)
        {
            map[p]++;
        }
        
        for (auto p : ransomNote)
        {
            if (!map.count(p) || map[p] <= 0)
            {
                return false;
            }
            
            map[p]--;
        }
        
        return true;
        
    }
