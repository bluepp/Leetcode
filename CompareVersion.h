/*
  bluepp
  2014-12-17
  May the force be with me!
  
  Compare Version Numbers Total Accepted: 560 Total Submissions: 4228 My Submissions Question Solution 
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

*/

/*https://oj.leetcode.com/discuss/18716/simple-c-solution */
    int compareVersion(string version1, string version2) {
        
        int v1 = 0, v2 = 0;
        int n1 = 0, n2 = 0;
        while (v1 < version1.size() || v2 < version2.size())
        {
            while (v1 < version1.size())
            {
                if (version1[v1] == '.') break;
                n1 = n1 * 10 + version1[v1]-'0';
                v1++;
            }
            
            while (v2 < version2.size())
            {
                if (version2[v2] == '.') break;
                n2 = n2*10 + version2[v2]-'0';
                v2++;
            }
            
            if (n1 != n2)
            {
                return n1 > n2 ? 1 : -1;
            }
            
            n1 = 0;
            n2 = 0;
            
            v1 ++;
            v2 ++;
            
        }
        
        return 0;
        
    }
    
    /* https://oj.leetcode.com/discuss/18704/a-concise-c-version */
        int compareVersion(string version1, string version2) {
        int pos1 = 0, pos2=0,token1, token2;
        string delimiter = ".";
        pos1 =version1.find(delimiter);
        pos2 =version2.find(delimiter);
        if(pos1 >=0 ) token1 = stoi(version1.substr(0,pos1));
        else token1 = version1.empty()?0:stoi(version1);
        if(pos2 >=0 ) token2 = stoi(version2.substr(0,pos2));
        else token2 = version2.empty()?0:stoi(version2);
        int diff = token1-token2;
        if(diff==0){
            if(pos1<0 && pos2<0) 
                return 0;
            version1= pos1>=0?version1.erase(0, pos1+1):"0";
            version2= pos2>=0?version2.erase(0, pos2+1):"0";  
            return compareVersion(version1, version2);
        }
        else return diff>0?1:-1;
    }
    
