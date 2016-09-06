/*
  bluepp
  2014-10-28
  2014-12-21
  May the force be with me!
  
  Reverse Words in a String

  Given an input string, reverse the string word by word.
  For example,
  Given s = "the sky is blue",
  return "blue is sky the".
*/

/* 2016-09-06, update */

    void reverseWords(string &s) {
        
        int i = 0, j = 0, k = 0, wordcount = 0;
        
        while (true)
        {
            while (i < s.length() && s[i] == ' ')
            {
                i++;
            }
            
            if (i == s.length())
            {
                break;
            }
            
            if (wordcount)
            {
                s[j++] = ' ';
            }
            
            k = j;
            
            while (i < s.length() && s[i] != ' ')
            {
                s[j] = s[i];
                i++;
                j++;
            }
            
            _reverse(s, k, j-1);
            wordcount++;
        }
        
        s.resize(j);
        _reverse(s, 0, j-1);
        
    }
    
    void _reverse(string &s, int l, int r)
    {
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
    
    

    void reverseWords(string &s) {
    
        string rs;  
    
        for (int i = s.length()-1; i >= 0; )  
        {  
            while (i >= 0 && s[i] == ' ') i--;  
            if (i < 0) break;  
    
            if (!rs.empty()) rs.push_back(' ');  
    
            string t;  
    
            while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);  
    
            reverse(t.begin(), t.end());  
            rs.append(t);  
        }  
    
        s = rs;  
    }



void reverseWords(string &s) {
        string word; //tmp string to store each word
        string res; // result string
        int i=0;
        while (i<s.size()){
            if (char(s[i])==' ' && word.empty()){i++;continue;} //multiple spaces
            if (char(s[i])==' ' && !word.empty()){ //first space after a word
                res = word+" "+ res; //store the word
                word=""; //reset the word
                i++; continue;
            }
            if (char(s[i])!=' '){word=word+char(s[i]);i++; continue;} //non-space chars 
        }
         
        if (!word.empty()){ //last word
            s = word+" "+res;
        }else{
            s = res;
        }
        s = s.substr(0,s.size()-1); //eliminate the last space
    }
  
