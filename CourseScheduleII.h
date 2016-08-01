/*
bluepp
2016-06-09
May the force be with me!

https://leetcode.com/problems/course-schedule-ii/

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

*/

/* 2016-08-01, update */

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
       
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in_degree(numCourses, 0);
        
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
        
        
        vector<int> ret;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            
            ret.push_back(t);
            
            for (auto p : graph[t])
            {
                in_degree[p]--;
                if (in_degree[p] == 0)
                {
                    q.push(p);
                }
            }
        }
        
        return ret.size() == numCourses ? ret : vector<int>();
    }


    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> count_in(numCourses, 0);
        
        for (auto p : prerequisites)
        {
            count_in[p.first]++;
            graph[p.second].push_back(p.first);
        }
        
        vector<int> ans;
        for (int i = 0; i < numCourses; i++)
        {
            if (count_in[i] == 0)
            {
                ans.push_back(i);
            }
        }
        
        for (int curr = 0; curr < ans.size(); curr++)
        {
            for (auto it = graph[ans[curr]].begin(); it != graph[ans[curr]].end(); it++)
            {
                count_in[*it]--;
                if (count_in[*it] == 0)
                {
                    ans.push_back(*it);
                }
            }
        }
        
        return (ans.size() == numCourses) ? ans : vector<int>();
        
    }
