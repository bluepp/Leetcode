/*
    bluepp
    2014-06-3
    May the force be with me!
    
    Problem:    Binary Tree Zigzag Level Order Traversal
    Source:     https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
    Notes:
    Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left 
    to right, then right to left for the next level and alternate between).
    For example:
    Given binary tree {3,9,20,#,#,15,7},
         3
        / \
       9  20
      / \
     15  7
    return its zigzag level order traversal as:
        [
            [3],
            [20,9],
            [15,7]
        ]

    Solution: 1. Queue + reverse.
              2. Two stacks.
              3. Vector. Contributed by yinlinglin.
              
*/
