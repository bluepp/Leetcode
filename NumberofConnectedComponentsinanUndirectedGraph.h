/*
bluepp
2016-06-24
May the force be with me!

https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
*/

    int countComponents(int n, vector<pair<int, int>>& edges) {
        
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visit(n, false);
        
        for (auto p : edges)
        {
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                res++;
                _dfs(graph, visit, i);
            }
        }
        
        return res;
    }
    
    void _dfs(vector<vector<int>>&graph, vector<bool>& visit, int i)
    {
        if (visit[i]) return;
        
        visit[i] = true;
        
        for (int j = 0; j < graph[i].size(); j++)
        {
            _dfs(graph, visit, graph[i][j]);
        }
    }
    
    
    
    /* solution 2 */
       int countComponents(int n, vector<pair<int, int>>& edges) {
        
        int res = n;
        vector<int> root(n);
        
        for (int i = 0; i < n; ++i) root[i] = i;
        
        for (auto a : edges) {
            int x = find(root, a.first), y = find(root, a.second);
            if (x != y) {
                --res;
                root[y] = x;
            }
        }
        
        return res;
    }
    
    int find(vector<int> &root, int i) {
        
        while (root[i] != i) i = root[i];
        return i;
    }
    
