/*
    bluepp
    2014-06-29
    May the force be with me!
    
    
 Problem:    Text Justification
 Source:     https://oj.leetcode.com/problems/text-justification/
 Notes:
 Given an array of words and a length L, format the text such that each line has exactly L 
 characters and is fully (left and right) justified.
 You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
 Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 Extra spaces between words should be distributed as evenly as possible. If the number of spaces 
 on a line do not divide evenly between words, the empty slots on the left will be assigned more 
 spaces than the slots on the right.
 For the last line of text, it should be left justified and no extra space is inserted between words.

 For example,
 words: ["This", "is", "an", "example", "of", "text", "justification."]
 L: 16.
 Return the formatted lines as:
 [
 "This    is    an",
 "example  of text",
 "justification.  "
 ]
 Note: Each word is guaranteed not to exceed L in length.
 Corner Cases:
 A line other than the last line might contain only one word. What should you do in this case?
 In this case, that line should be left-justified.

 Solution: ...
 */
 
 
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0, n = words.size();
        
        while (i < n)
        {
            int length = words[i].size();
            int j = i+1;
            
            while (j < n && length + words[j].size() + (j-i) <= L)
            {
                length += words[j++].size();
            }
            
            string s(words[i]);
            bool isLastLine = (j == n);
            bool oneWord = (j == i+1);
            int average = isLastLine || oneWord ? 1 : (L-length) / (j - i - 1);
            int extra = isLastLine || oneWord ? 0 : (L - length) % (j - i - 1);
            
            for (int k = i+1; k < j; k++)
            {
                s.append(extra > 0 ? average+1 : average, ' ');
                s.append(words[k]);
                extra--;
            }
            
            s.append(L - s.size(), ' ');
            res.push_back(s);
            i = j;
        }
        
        return res;
        
    }
