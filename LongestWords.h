/* 
  2015-09-05
  bluepp
  May the force be with me!
 
 
Given a dictionary, find all of the longest words in the dictionary.

Have you met this question in a real interview? Yes
Example
Given

{
  "dog",
  "google",
  "facebook",
  "internationalization",
  "blabla"
}
the longest words are(is) ["internationalization"].

Given

{
  "like",
  "love",
  "hate",
  "yes"
}
the longest words are ["like", "love", "hate"].
http://www.lintcode.com/en/problem/longest-words/#

*/

    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        int n = 0;
        
        for (auto p : dictionary)
        {
            if (p.length() < n) continue;
            else if (p.length() == n)
            {
                res.push_back(p);
            }
            else
            {
                n = p.length();
                res.clear();
                res.push_back(p);
            }
        }
        
        return res;
    }


