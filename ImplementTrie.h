/*
  2015-06-25
  bluepp
  May the force be with me!
  
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.

https://leetcode.com/problems/implement-trie-prefix-tree/
*/

/* 2015-07-01, update, remove return out of loop */

class TrieNode {
    public:
        TrieNode() : isword(false) {}
        bool isword;
        unordered_map<char, TrieNode*> map;
};

class Trie {    
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        
        TrieNode *node = root;
        
        int i = 0;
        for (; i < word.length(); i++)
        {
            if (node->map.find(word[i]) == node->map.end())
            {
                node->map.insert(make_pair(word[i], new TrieNode()));
            }
            node = node->map.find(word[i])->second;
        }
        
        node->isword = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        
        TrieNode *node = root;
        
        int i = 0;
        for (; i < word.size(); i++)
        {
            if (node->map.find(word[i]) == node->map.end()) return false;
            node = node->map.find(word[i])->second;
        }
        
        return node->isword;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        
        TrieNode *node = root;
        
        int i = 0;
        for (; i < prefix.size(); i++)
        {
            if (node->map.find(prefix[i]) == node->map.end()) return false;
            node = node->map.find(prefix[i])->second;
        }
        
        return true;
    }
    
private:
    TrieNode* root;;
};





/*  ---------------------------------------------- */
class TrieNode {
    public:
        TrieNode() : isword(false) {}
        bool isword;
        unordered_map<char, TrieNode*> children;
};
  
class Trie {    
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            if (node->children.find(word[i]) == node->children.end())
            {
                node->children.insert(make_pair(word[i], new TrieNode()));
            }
            
            node = node->children.find(word[i])->second;
            if (i == word.length()-1) node->isword = true;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            if (node->children.find(word[i]) == node->children.end())
            {
                return false;
            }
            
            node = node->children.find(word[i])->second;
            if (i == word.length()-1) return node->isword;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        
        for (int i = 0; i < prefix.length(); i++)
        {
            if (node->children.find(prefix[i]) == node->children.end())
            {
                return false;
            }
            
            node = node->children.find(prefix[i])->second;
        }
        
        return true;
    }

private:
    TrieNode* root;
};
