/*
	bluepp	
	2014-06-05
	2014-12-22
	May the force be with me!
	
	 
 	Problem:    Clone Graph
  	Source:     http://oj.leetcode.com/problems/clone-graph/
 	Notes:
 	Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 	OJ's undirected graph serialization:
 	Nodes are labeled from 0 to N - 1, where N is the total nodes in the graph.
 	We use # as a separator for each node, and , as a separator for each neighbor of the node.
 	As an example, consider the serialized graph {1,2#2#2}.
 	The graph has a total of three nodes, and therefore contains three parts as separated by #.
 	Connect node 0 to both nodes 1 and 2.
 	Connect node 1 to node 2.
 	Connect node 2 to node 2 (itself), thus forming a self-cycle.
 	Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

 	Solution: 1. DFS. 2. BFS.
 */
 
 /* DFS */
     typedef UndirectedGraphNode GraphNode;
    typedef unordered_map<GraphNode*, GraphNode*> MAP;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        MAP map;
        return _clone(node, map);
    }
    
    GraphNode* _clone(GraphNode *node, MAP &map)
    {
        if (!node) return NULL;
        if (map.find(node) != map.end()) return map[node];
        
        GraphNode *newNode = new GraphNode(node->label);
        map[node] = newNode;
        
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            newNode->neighbors.push_back(_clone(node->neighbors[i], map));
        }
        
        return newNode;
    }
  
/* BFS */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        MAP map;
        return _clone(node);
    }
    
    GraphNode* _clone(GraphNode *node)
    {
        if (node == NULL) return NULL;
        
        unordered_map<GraphNode*, GraphNode*> nodesmap;
        nodesmap[node] = new GraphNode(node->label) ;
        queue<GraphNode *> q;
        q.push(node);
        
        while (!q.empty())
        {
            GraphNode *tmp = q.front();
            q.pop();
            
            for (int i = 0; i < tmp->neighbors.size(); i++)
            {
                GraphNode *neigh = tmp->neighbors[i];
                
                if (nodesmap.find(neigh) == nodesmap.end())
                {
                    GraphNode *newNode = new GraphNode (neigh->label);
                    nodesmap[neigh] = newNode;
                    q.push(neigh);
                }
                
                nodesmap[tmp]->neighbors.push_back(nodesmap[neigh]);
            }
        }
        
        return nodesmap[node];
      
    }

