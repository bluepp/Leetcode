/*
    bluepp
    
    2014-06-23
    2014-07-26
    2014-08-20
    2014-12-04
    2014-12-09
    
    May the force be with me!
    
     
 Problem:    Simplify Path
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/simplify-path/
 Notes:
 Given an absolute path for a file (Unix-style), simplify it.

 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"

 Corner Cases:
 Did you consider the case where path = "/../"?
 In this case, you should return "/".
 Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".

 Solution: Add an additional '/' at the end of 'path' for simply detecting the end.
 */
 
 
 /* 2014-12-09 */
 /*http://bangbingsyb.blogspot.com/search?q=simplify+path */
     string simplifyPath(string path) {
                string ret, curDir;
        vector<string> allDir;
        
        path.push_back('/');
        for(int i=0; i<path.size(); i++) {
            if(path[i]=='/') {
                if(curDir.empty()) {
                    continue;
                }
                else if(curDir==".") {
                    curDir.clear();
                }
                else if(curDir=="..") {
                    if(!allDir.empty())
                        allDir.pop_back();
                    curDir.clear();
                }
                else {
                    allDir.push_back(curDir);
                    curDir.clear();
                }
            }
            else {
                curDir.push_back(path[i]);
            }
        }
        
        
        for(int i=0; i<allDir.size(); i++) 
            ret.append("/"+allDir[i]);
        if(ret.empty()) ret = "/";
        return ret;
       
    }
 
 
 
 
 
    string simplifyPath(string path) {
        string res;
        path += "/";
        size_t pos = path.find_first_of("/"), last = 0;
        while (pos != string::npos)
        {
            string s = path.substr(last, pos - last);
            if (s == "..") 
            {
                if (!res.empty())
                    res.resize(res.find_last_of("/"));
            }
            else if (!s.empty() && s != ".")
            {
                res += "/";
                res += s;
            }
            last = pos + 1;
            pos = path.find_first_of("/", last);
        }
        return res.empty() ? "/" : res;
        
    }
