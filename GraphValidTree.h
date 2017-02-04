/*
  2015-08-18
  bluepp
  May the force be with me!
  
  Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
  write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Show Hint 
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected,
[0, 1] is the same as [1, 0] and thus will not appear together in edges.

https://leetcode.com/problems/graph-valid-tree/
*/

/* 1. Union Find,  http://www.fgdsb.com/2015/02/16/valid-tree/ */

class UnionFind
{
    private:
        vector<int> father, ranks;
        int nums{0};
    public:
        UnionFind(int num_nodes) : nums(num_nodes)
        {
            for (int i = 0; i < num_nodes; i++)
            {
                father.push_back(i);
                ranks.push_back(0);
            }
        }
        
        int find(int x)
        {
            if (x == father[x]) return x;
            return father[x] = find(father[x]);
        }
        
        void do_union(int x, int y)
        {
            x = find(x); 
            y = find(y);
            
            if (x == y) return;
            if (ranks[x] < ranks[y])
            {
                father[x]= y;
            }
            else
            {
                father[y] = x;
                if (ranks[x] == ranks[y])
                {
                    ranks[x]++;
                }
            }
        }
        
        int num_sets()
        {
            int count = 0;
            
            for (int i = 0; i < nums; i++)
            {
                if (father[i] == i) count ++;
            }
            
            return count;
        }
};


    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (!n) return false;
        
        UnionFind u(n);
        for (auto p : edges)
        {
            if (u.find(p.first) == u.find(p.second))
            {
                return false;
            }
            
            u.do_union(p.first, p.second);
        }
        
        return u.num_sets() == 1;
    }


/* regular graph, if there is no loop, it is a tree */
/* http://www.fgdsb.com/2015/02/16/valid-tree/ */

/* 2017-02-04, update */
    bool validTree(int n, vector<pair<int, int>>& edges) {
        
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> v(n, false);
        
        for (auto p : edges)
        {
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
        }
        
        if (!_dfs(graph, v, 0, -1)) return false;
        
        for (auto p : v)
        {
            if (!p) return false;
        }
        
        return true;
    }
    
    bool _dfs(vector<vector<int>> &g, vector<bool> &v, int cur, int pre) {
        if (v[cur]) return false;
        v[cur] = true;
        for (auto a : g[cur]) {
            if (a != pre) {
                if (!_dfs(g, v, a, cur)) return false;
            }
        }
        return true;
    }
