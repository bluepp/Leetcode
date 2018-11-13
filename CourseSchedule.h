/*
  2015-06-21
  bluepp
  May the force be with me!
  
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1.
So it is impossible.

https://leetcode.com/problems/course-schedule/
*/


/* DFS */

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> visited(numCourses, 0);
        
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visited, i)) return false;
        }
        
        return true;
    }
    
    bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a)) return false;
        }
        visit[i] = 1;
        return true;
    }


/* 2017-03-02, my version, seems fine, res.size() == numCourses */

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        vector<int> res;
        
        for (auto p : prerequisites)
        {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            res.push_back(it);
            
            for (auto p : graph[it])
            {
                if (--in_degree[p] == 0)
                {
                    q.push(p);
                }
            }
            
        }
        
        return res.size() == numCourses;
        
    
    }



/* bfs, 2016-07-13, update */

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] != 0) return false;
        }
        
        return true;
        
    }

/* bfs , 2016-06-23 update */

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in_degree(numCourses, 0);
        
        for (auto p : prerequisites)
        {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++;
        }
        
        queue<int> zeros;
        for (int i = 0; i < numCourses; i++)
        {
            if (in_degree[i] == 0)
            {
                zeros.push(i);
            }
        }
        
        
        while (!zeros.empty())
        {
            int seq = zeros.front();
            zeros.pop();
            
            for (auto it = graph[seq].begin(); it != graph[seq].end(); it++)
            {
                in_degree[*it]--;
                
                if (in_degree[*it] == 0)
                {
                    zeros.push(*it);
                    
                }
            }
            
            numCourses--;
        }
        
        return numCourses == 0;
    }



/* bfs */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<unordered_set<int> > need(numCourses);
        
        for (int i = 0; i < prerequisites.size(); ++i)
            need[prerequisites[i].second].insert(prerequisites[i].first);
            
        vector<int> indegree(numCourses);
        for (int i = 0; i < numCourses; ++i)
        {
            for(auto it = need[i].begin(); it != need[i].end(); ++it)
                ++indegree[*it];
        }
                
        queue<int> zeros;
        for (int i = 0; i != numCourses; ++i)
            if (indegree[i] == 0)
                zeros.push(i);
                
        while (!zeros.empty()) {
            int seq = zeros.front();
            zeros.pop();
            
            for (auto it = need[seq].begin(); it != need[seq].end(); ++it)
                if (--indegree[*it] == 0)
                    zeros.push(*it);
            --numCourses;
        }
        
        return numCourses == 0;
    }

  
