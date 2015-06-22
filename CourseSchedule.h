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

  
