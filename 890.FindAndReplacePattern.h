    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        
        for (auto word : words) {
            if (_ispattern(word, pattern)) {
                res.push_back(word);
            }
        }
        
        return res;
       
    }
    
    
    bool _ispattern(string p1, string p2) {
        unordered_map<char,char> m1, m2;
        
        for (int i = 0; i < p1.size(); i++) {
            if (m1.count(p1[i]) && m1[p1[i]] != p2[i]) {
                return false;
            } else if (m2.count(p2[i]) && m2[p2[i]] != p1[i]) {
                return false;
            } else {
                m1[p1[i]] = p2[i];
                m2[p2[i]] = p1[i];
            }
        }
        
        return true;
    }
