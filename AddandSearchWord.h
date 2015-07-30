/*
  2015-06-30
  bluepp
  May the force be with me!
  
Add and Search Word - Data structure design
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

https://leetcode.com/problems/add-and-search-word-data-structure-design/
*/



/* my version, failed on test, why?  2015-07-30, update*/
class TrieNode
{
public:    
    TrieNode():isword(false){}
    bool isword;
    unordered_map<char, TrieNode*> map;
};

class WordDictionary {

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
        
        for (int i = 0; i < word.size(); i++)
        {
            if (node->map.find(word[i]) == node->map.end())
            {
                node->map.insert(make_pair(word[i], new TrieNode()));
            }
            
            node = node->map.find(word[i])->second;
        }
        
        node->isword = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode *node = root;
        
        return _search(word.c_str(), node);
    }
    
private:
    TrieNode *root;
    
    bool _search(const char *word, TrieNode *node)
    {
        TrieNode *p = node;
        for (int i = 0; word[i]; i++)
        {
            if (word[i] == '.')
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    auto t = p->map.find(c);
                    
                    if (t == p->map.end() && c != 'z') continue;
                    else if (t == p->map.end()) return false;
                    else
                    {
                        p = t->second;
                        return _search(word+i+1, p);
                    }
                }
            }
            else
            {
                if (p->map.find(word[i]) == p->map.end()) return false;
                p = p->map.find(word[i])->second;
            }
        }
       
        return p->isword;
    }

};



/* Trie, https://leetcode.com/discuss/39022/80ms-clear-c-code-with-detailed-explanations */
class TrieNode
{
    public:
        bool isKey;
        TrieNode *children[26];
        TrieNode()
        {
            isKey = false;
            
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
        }
};


class WordDictionary {
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            if (!(node->children[word[i]-'a']))
            {
                node->children[word[i]-'a'] = new TrieNode();
            }
            
            node = node->children[word[i]-'a'];
        }
        
        node->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search_help(word.c_str(), root);
    }
    
private:
    TrieNode *root;
    
    bool search_help(const char *word, TrieNode* node)
    {
        if (!node) return false;
        if (!*word) return node->isKey;
        
        TrieNode *run = node;
        for (int i = 0; word[i];i++)
        {
            if (run && word[i] != '.')
            {
                run = run->children[word[i]-'a'];
            }
            else if (run && word[i] == '.')
            {
                TrieNode *tmp = run;
                
                for (int j = 0; j < 26; j++)
                {
                    run = tmp->children[j];
                    
                    if (search_help(word+i+1, run)) return true;
                }
            }
            else break;
        }
        
        if (!run) return false;
        return run->isKey;
    }
};

