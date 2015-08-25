/*
  2015-08-25
  bluepp
  May the force be woth me!
  
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you.
You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
https://leetcode.com/problems/alien-dictionary/

*/


/* topo sort, does not pass */
class Graph
{
    private:
        int _num_verts{0};
        unordered_set<int> *_adjs{NULL};
    public:
        Graph(int numVert) : _num_verts(numVert)
        {
            _adjs = new unordered_set<int>[numVert];
        }
        
        ~Graph()
        {
            if (_adjs)
            {
                delete [] _adjs;
                _adjs = NULL;
            }
        }
        
        void add_edge(int v, int w)
        {
            _adjs[v].insert(w);
        }
        
        vector<int> topo_sort()
        {
            vector<int> ret;
            vector<bool> visited(_num_verts, false);
            
            function<void(int)> visit = [&](int v)
            {
                visited[v] = true;
                for (auto adj : _adjs[v])
                {
                    if (!visited[adj]) visit(adj);
                }
                ret.push_back(v);
            };
            
            for (auto i = 0; i < _num_verts; i++)
            {
                if (!visited[i]) visit(i);
            }
            
            return ret;
        }
        
        bool has_cycle()
        {
            vector<bool> visited(_num_verts, false);
            vector<bool> recstack(_num_verts, false);
            
            function<bool(int) > cycle = [&](int node)
            {
                if (!visited[node]) 
                {
                    visited[node] = recstack[node];
                    
                    for (auto adj : _adjs[node])
                    {
                        if (!visited[adj] && cycle(adj)) return true;
                        else if (recstack[adj]) return true;
                    }
                }
                
                recstack[node] = false;
                return false;
            };
            
            for (auto i = 0; i < _num_verts; i++)
            {
                if (cycle(i)) return true;
            }
            
            return false;
        }
        
};


class Solution {
public:
    string alienOrder(vector<string>& words) {
        Graph g(26);
        
        auto build_graph = [&](const string &w1, const string &w2)
        {
            auto len = min(w1.length(), w2.length());
            for (int i = 0; i < len; i++)
            {
                if (w1[i] < w2[i])
                {
                    g.add_edge(w1[i]-'a',w2[i]-'a');
                }
                else if (w1[i] > w2[i])
                {
                    g.add_edge(w2[i]-'a', w1[i]-'a');
                }
            }
        };
        
        for (auto i = 0; i < words.size()-1; i++)
        {
            build_graph(words[i], words[i+1]);
        }
        
        if (g.has_cycle()) return "";
        
        vector<int> sorted = g.topo_sort();
        
        string ret;
        for (auto p : sorted)
        {
            ret += 'a'+p;
        }
        
        return ret;
    }
};
