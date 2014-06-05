/*
	bluepp	
	2014-06-05
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
